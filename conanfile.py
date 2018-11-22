
from conans import ConanFile, CMake, tools
from pathlib import Path
import os

homedir = Path.home()
conan_dir = os.path.join(homedir, ".conan")
conan_bin_dir = os.path.join(conan_dir, "bin")
if not os.path.exists(conan_bin_dir):
    os.mkdir(conan_bin_dir)


class wanzhuanwxConan(ConanFile):
    name = "wanzhuanwx"
    version = "0.0.1"
    license = "LGPL"
    author = "kaiyin keezhong@qq.com"
    url = "https://github.com/kindlychung/wanzhuanwx"
    description = "change_your_description"
    topics = ("cpp", )
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    requires = ("docopt/0.6.2@conan/stable",
                "wxwidgets/3.1.1@jzien/dev")
    generators = "cmake"
    exports_sources = "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

    def package(self):
        self.copy("*", dst="bin", src="bin")

    def imports(self):
        self.copy("*", dst="include", src="include")
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy("*.a", dst="bin", src="lib")
        self.copy("*.so", dst="bin", src="lib")

    def deploy(self):
        self.copy("*", src="bin", dst=conan_bin_dir)
