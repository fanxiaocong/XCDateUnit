
Pod::Spec.new do |s|

  s.name         = "XCDateUnit"
  s.version      = "0.0.2"
  s.summary      = "与时间有关的工具类"

  s.description  = <<-DESC
XCDateUnit，与时间有关的工具类
                   DESC

  s.homepage     = "https://github.com/fanxiaocong/XCDateUnit"
  s.license      = "MIT"
  s.author       = { "樊小聪" => "1016697223@qq.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/fanxiaocong/XCDateUnit.git", :tag => "#{s.version}" }

  s.source_files  = "XCDateUnit/*.{h,m}"
end
