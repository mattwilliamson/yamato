<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="stm32f0discovery">
<packages>
<package name="STM32F0DISCOVERY-PACKAGE">
<pad name="PA1" x="-19.05" y="2.54" drill="0.8"/>
<pad name="PA0" x="-19.05" y="5.08" drill="0.8"/>
<pad name="PC3" x="-19.05" y="7.62" drill="0.8"/>
<pad name="PC2" x="-19.05" y="10.16" drill="0.8"/>
<pad name="PC1" x="-19.05" y="12.7" drill="0.8"/>
<pad name="PC0" x="-19.05" y="15.24" drill="0.8"/>
<pad name="NRST" x="-19.05" y="17.78" drill="0.8"/>
<pad name="GND2" x="-19.05" y="20.32" drill="0.8"/>
<pad name="PF1" x="-19.05" y="22.86" drill="0.8"/>
<pad name="PF0" x="-19.05" y="25.4" drill="0.8"/>
<pad name="PC15" x="-19.05" y="27.94" drill="0.8"/>
<pad name="PC14" x="-19.05" y="30.48" drill="0.8"/>
<pad name="PC13" x="-19.05" y="33.02" drill="0.8"/>
<pad name="VBAT" x="-19.05" y="35.56" drill="0.8"/>
<pad name="GND" x="-19.05" y="38.1" drill="0.8"/>
<pad name="PA15" x="19.05" y="2.54" drill="0.8"/>
<pad name="PC10" x="19.05" y="5.08" drill="0.8"/>
<pad name="PC11" x="19.05" y="7.62" drill="0.8"/>
<pad name="PC12" x="19.05" y="10.16" drill="0.8"/>
<pad name="PD2" x="19.05" y="12.7" drill="0.8"/>
<pad name="PB3" x="19.05" y="15.24" drill="0.8"/>
<pad name="PB4" x="19.05" y="17.78" drill="0.8"/>
<pad name="PB5" x="19.05" y="20.32" drill="0.8"/>
<pad name="PB6" x="19.05" y="22.86" drill="0.8"/>
<pad name="PB7" x="19.05" y="25.4" drill="0.8"/>
<pad name="BOOT0" x="19.05" y="27.94" drill="0.8"/>
<pad name="VDD" x="19.05" y="30.48" drill="0.8"/>
<pad name="PB8" x="19.05" y="33.02" drill="0.8"/>
<pad name="PB9" x="19.05" y="35.56" drill="0.8"/>
<pad name="GND4" x="19.05" y="38.1" drill="0.8"/>
<pad name="PB12" x="-19.05" y="-38.1" drill="0.8"/>
<pad name="PB11" x="-19.05" y="-35.56" drill="0.8"/>
<pad name="PB10" x="-19.05" y="-33.02" drill="0.8"/>
<pad name="PB2" x="-19.05" y="-30.48" drill="0.8"/>
<pad name="PB1" x="-19.05" y="-27.94" drill="0.8"/>
<pad name="PB0" x="-19.05" y="-25.4" drill="0.8"/>
<pad name="PC5" x="-19.05" y="-22.86" drill="0.8"/>
<pad name="PC4" x="-19.05" y="-20.32" drill="0.8"/>
<pad name="PA7" x="-19.05" y="-17.78" drill="0.8"/>
<pad name="PA6" x="-19.05" y="-15.24" drill="0.8"/>
<pad name="PA5" x="-19.05" y="-12.7" drill="0.8"/>
<pad name="PA4" x="-19.05" y="-10.16" drill="0.8"/>
<pad name="PF5" x="-19.05" y="-7.62" drill="0.8"/>
<pad name="PF4" x="-19.05" y="-5.08" drill="0.8"/>
<pad name="PA3" x="-19.05" y="-2.54" drill="0.8"/>
<pad name="PA2" x="-19.05" y="0" drill="0.8"/>
<pad name="PB13" x="19.05" y="-38.1" drill="0.8"/>
<pad name="PB14" x="19.05" y="-35.56" drill="0.8"/>
<pad name="PB15" x="19.05" y="-33.02" drill="0.8"/>
<pad name="PC6" x="19.05" y="-30.48" drill="0.8"/>
<pad name="PC7" x="19.05" y="-27.94" drill="0.8"/>
<pad name="PC8" x="19.05" y="-25.4" drill="0.8"/>
<pad name="PC9" x="19.05" y="-22.86" drill="0.8"/>
<pad name="PA8" x="19.05" y="-20.32" drill="0.8"/>
<pad name="PA9" x="19.05" y="-17.78" drill="0.8"/>
<pad name="PA10" x="19.05" y="-15.24" drill="0.8"/>
<pad name="PA11" x="19.05" y="-12.7" drill="0.8"/>
<pad name="PA12" x="19.05" y="-10.16" drill="0.8"/>
<pad name="PA13" x="19.05" y="-7.62" drill="0.8"/>
<pad name="PF6" x="19.05" y="-5.08" drill="0.8"/>
<pad name="PF7" x="19.05" y="-2.54" drill="0.8"/>
<pad name="PA14" x="19.05" y="0" drill="0.8"/>
<pad name="3V" x="-19.05" y="40.64" drill="0.8" shape="square"/>
<pad name="5V" x="19.05" y="40.64" drill="0.8" shape="square"/>
<wire x1="25" y1="45" x2="-25" y2="45" width="0.127" layer="20"/>
<wire x1="-25" y1="45" x2="-25" y2="-45" width="0.127" layer="20"/>
<wire x1="-25" y1="-45" x2="25" y2="-45" width="0.127" layer="20"/>
<wire x1="25" y1="-45" x2="25" y2="45" width="0.127" layer="20"/>
<pad name="GND3" x="-19.05" y="-40.64" drill="0.8"/>
<pad name="GND5" x="19.05" y="-40.64" drill="0.8"/>
<wire x1="-4" y1="45" x2="-4" y2="38" width="0.127" layer="22"/>
<wire x1="-4" y1="38" x2="4" y2="38" width="0.127" layer="22"/>
<wire x1="4" y1="38" x2="4" y2="45" width="0.127" layer="22"/>
<text x="-22.86" y="40.005" size="1.27" layer="20">3V</text>
<text x="20.955" y="40.005" size="1.27" layer="20">5V</text>
</package>
</packages>
<symbols>
<symbol name="STM32F0DISCOVERY-SYMBOL">
<wire x1="17.78" y1="-45.72" x2="-17.78" y2="-45.72" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-45.72" x2="-17.78" y2="40.64" width="0.254" layer="94"/>
<wire x1="-17.78" y1="40.64" x2="17.78" y2="40.64" width="0.254" layer="94"/>
<wire x1="17.78" y1="40.64" x2="17.78" y2="-45.72" width="0.254" layer="94"/>
<pin name="3V" x="-22.86" y="38.1" length="middle"/>
<pin name="GND" x="-22.86" y="35.56" length="middle"/>
<pin name="VBAT" x="-22.86" y="33.02" length="middle"/>
<pin name="PC13" x="-22.86" y="30.48" length="middle"/>
<pin name="PC14" x="-22.86" y="27.94" length="middle"/>
<pin name="PC15" x="-22.86" y="25.4" length="middle"/>
<pin name="PF0" x="-22.86" y="22.86" length="middle"/>
<pin name="PF1" x="-22.86" y="20.32" length="middle"/>
<pin name="GND1" x="-22.86" y="17.78" length="middle"/>
<pin name="NRST" x="-22.86" y="15.24" length="middle"/>
<pin name="PC0" x="-22.86" y="12.7" length="middle"/>
<pin name="PC1" x="-22.86" y="10.16" length="middle"/>
<pin name="PC2" x="-22.86" y="7.62" length="middle"/>
<pin name="PC3" x="-22.86" y="5.08" length="middle"/>
<pin name="PA0" x="-22.86" y="2.54" length="middle"/>
<pin name="PA1" x="-22.86" y="0" length="middle"/>
<pin name="PA2" x="-22.86" y="-2.54" length="middle"/>
<pin name="PA3" x="-22.86" y="-5.08" length="middle"/>
<pin name="PF4" x="-22.86" y="-7.62" length="middle"/>
<pin name="PF5" x="-22.86" y="-10.16" length="middle"/>
<pin name="PA4" x="-22.86" y="-12.7" length="middle"/>
<pin name="PA5" x="-22.86" y="-15.24" length="middle"/>
<pin name="PA6" x="-22.86" y="-17.78" length="middle"/>
<pin name="PA7" x="-22.86" y="-20.32" length="middle"/>
<pin name="PC4" x="-22.86" y="-22.86" length="middle"/>
<pin name="PC5" x="-22.86" y="-25.4" length="middle"/>
<pin name="PB0" x="-22.86" y="-27.94" length="middle"/>
<pin name="PB1" x="-22.86" y="-30.48" length="middle"/>
<pin name="PB2" x="-22.86" y="-33.02" length="middle"/>
<pin name="PB10" x="-22.86" y="-35.56" length="middle"/>
<pin name="PB11" x="-22.86" y="-38.1" length="middle"/>
<pin name="PB12" x="-22.86" y="-40.64" length="middle"/>
<pin name="GND3" x="-22.86" y="-43.18" length="middle"/>
<pin name="GND5" x="22.86" y="-43.18" length="middle" rot="R180"/>
<pin name="PB13" x="22.86" y="-40.64" length="middle" rot="R180"/>
<pin name="PB14" x="22.86" y="-38.1" length="middle" rot="R180"/>
<pin name="PB15" x="22.86" y="-35.56" length="middle" rot="R180"/>
<pin name="PC6" x="22.86" y="-33.02" length="middle" rot="R180"/>
<pin name="PC7" x="22.86" y="-30.48" length="middle" rot="R180"/>
<pin name="PC8" x="22.86" y="-27.94" length="middle" rot="R180"/>
<pin name="PC9" x="22.86" y="-25.4" length="middle" rot="R180"/>
<pin name="PA8" x="22.86" y="-22.86" length="middle" rot="R180"/>
<pin name="PA9" x="22.86" y="-20.32" length="middle" rot="R180"/>
<pin name="PA10" x="22.86" y="-17.78" length="middle" rot="R180"/>
<pin name="PA11" x="22.86" y="-15.24" length="middle" rot="R180"/>
<pin name="PA12" x="22.86" y="-12.7" length="middle" rot="R180"/>
<pin name="PA13" x="22.86" y="-10.16" length="middle" rot="R180"/>
<pin name="PF6" x="22.86" y="-7.62" length="middle" rot="R180"/>
<pin name="PF7" x="22.86" y="-5.08" length="middle" rot="R180"/>
<pin name="PA14" x="22.86" y="-2.54" length="middle" rot="R180"/>
<pin name="PA15" x="22.86" y="0" length="middle" rot="R180"/>
<pin name="PC10" x="22.86" y="2.54" length="middle" rot="R180"/>
<pin name="PC11" x="22.86" y="5.08" length="middle" rot="R180"/>
<pin name="PC12" x="22.86" y="7.62" length="middle" rot="R180"/>
<pin name="PD2" x="22.86" y="10.16" length="middle" rot="R180"/>
<pin name="PB3" x="22.86" y="12.7" length="middle" rot="R180"/>
<pin name="PB4" x="22.86" y="15.24" length="middle" rot="R180"/>
<pin name="PB5" x="22.86" y="17.78" length="middle" rot="R180"/>
<pin name="PB6" x="22.86" y="20.32" length="middle" rot="R180"/>
<pin name="PB7" x="22.86" y="22.86" length="middle" rot="R180"/>
<pin name="BOOT0" x="22.86" y="25.4" length="middle" rot="R180"/>
<pin name="VDD" x="22.86" y="27.94" length="middle" rot="R180"/>
<pin name="PB8" x="22.86" y="30.48" length="middle" rot="R180"/>
<pin name="PB9" x="22.86" y="33.02" length="middle" rot="R180"/>
<pin name="GND4" x="22.86" y="35.56" length="middle" rot="R180"/>
<pin name="5V" x="22.86" y="38.1" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="STM32F0DISCOVERY-DEVICE">
<gates>
<gate name="G$1" symbol="STM32F0DISCOVERY-SYMBOL" x="0" y="0"/>
</gates>
<devices>
<device name="" package="STM32F0DISCOVERY-PACKAGE">
<connects>
<connect gate="G$1" pin="3V" pad="3V"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="BOOT0" pad="BOOT0"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND1" pad="GND2"/>
<connect gate="G$1" pin="GND3" pad="GND3"/>
<connect gate="G$1" pin="GND4" pad="GND4"/>
<connect gate="G$1" pin="GND5" pad="GND5"/>
<connect gate="G$1" pin="NRST" pad="NRST"/>
<connect gate="G$1" pin="PA0" pad="PA0"/>
<connect gate="G$1" pin="PA1" pad="PA1"/>
<connect gate="G$1" pin="PA10" pad="PA10"/>
<connect gate="G$1" pin="PA11" pad="PA11"/>
<connect gate="G$1" pin="PA12" pad="PA12"/>
<connect gate="G$1" pin="PA13" pad="PA13"/>
<connect gate="G$1" pin="PA14" pad="PA14"/>
<connect gate="G$1" pin="PA15" pad="PA15"/>
<connect gate="G$1" pin="PA2" pad="PA2"/>
<connect gate="G$1" pin="PA3" pad="PA3"/>
<connect gate="G$1" pin="PA4" pad="PA4"/>
<connect gate="G$1" pin="PA5" pad="PA5"/>
<connect gate="G$1" pin="PA6" pad="PA6"/>
<connect gate="G$1" pin="PA7" pad="PA7"/>
<connect gate="G$1" pin="PA8" pad="PA8"/>
<connect gate="G$1" pin="PA9" pad="PA9"/>
<connect gate="G$1" pin="PB0" pad="PB0"/>
<connect gate="G$1" pin="PB1" pad="PB1"/>
<connect gate="G$1" pin="PB10" pad="PB10"/>
<connect gate="G$1" pin="PB11" pad="PB11"/>
<connect gate="G$1" pin="PB12" pad="PB12"/>
<connect gate="G$1" pin="PB13" pad="PB13"/>
<connect gate="G$1" pin="PB14" pad="PB14"/>
<connect gate="G$1" pin="PB15" pad="PB15"/>
<connect gate="G$1" pin="PB2" pad="PB2"/>
<connect gate="G$1" pin="PB3" pad="PB3"/>
<connect gate="G$1" pin="PB4" pad="PB4"/>
<connect gate="G$1" pin="PB5" pad="PB5"/>
<connect gate="G$1" pin="PB6" pad="PB6"/>
<connect gate="G$1" pin="PB7" pad="PB7"/>
<connect gate="G$1" pin="PB8" pad="PB8"/>
<connect gate="G$1" pin="PB9" pad="PB9"/>
<connect gate="G$1" pin="PC0" pad="PC0"/>
<connect gate="G$1" pin="PC1" pad="PC1"/>
<connect gate="G$1" pin="PC10" pad="PC10"/>
<connect gate="G$1" pin="PC11" pad="PC11"/>
<connect gate="G$1" pin="PC12" pad="PC12"/>
<connect gate="G$1" pin="PC13" pad="PC13"/>
<connect gate="G$1" pin="PC14" pad="PC14"/>
<connect gate="G$1" pin="PC15" pad="PC15"/>
<connect gate="G$1" pin="PC2" pad="PC2"/>
<connect gate="G$1" pin="PC3" pad="PC3"/>
<connect gate="G$1" pin="PC4" pad="PC4"/>
<connect gate="G$1" pin="PC5" pad="PC5"/>
<connect gate="G$1" pin="PC6" pad="PC6"/>
<connect gate="G$1" pin="PC7" pad="PC7"/>
<connect gate="G$1" pin="PC8" pad="PC8"/>
<connect gate="G$1" pin="PC9" pad="PC9"/>
<connect gate="G$1" pin="PD2" pad="PD2"/>
<connect gate="G$1" pin="PF0" pad="PF0"/>
<connect gate="G$1" pin="PF1" pad="PF1"/>
<connect gate="G$1" pin="PF4" pad="PF4"/>
<connect gate="G$1" pin="PF5" pad="PF5"/>
<connect gate="G$1" pin="PF6" pad="PF6"/>
<connect gate="G$1" pin="PF7" pad="PF7"/>
<connect gate="G$1" pin="VBAT" pad="VBAT"/>
<connect gate="G$1" pin="VDD" pad="VDD"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="uln-udn">
<description>&lt;b&gt;Driver Arrays&lt;/b&gt;&lt;p&gt;
ULN and UDN Series&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="DIL16">
<description>&lt;b&gt;Dual In Line Package&lt;/b&gt;</description>
<wire x1="10.16" y1="2.921" x2="-10.16" y2="2.921" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-2.921" x2="10.16" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="10.16" y1="2.921" x2="10.16" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="2.921" x2="-10.16" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-2.921" x2="-10.16" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="1.016" x2="-10.16" y2="-1.016" width="0.1524" layer="21" curve="-180"/>
<pad name="1" x="-8.89" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-6.35" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="6.35" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="8.89" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="-1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="9" x="8.89" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="10" x="6.35" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="11" x="3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="12" x="1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="13" x="-1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="14" x="-3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="15" x="-6.35" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="16" x="-8.89" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<text x="-10.541" y="-2.921" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-7.493" y="-0.635" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="SO16">
<description>&lt;b&gt;Small Outline Package&lt;/b&gt;</description>
<wire x1="4.699" y1="1.9558" x2="-4.699" y2="1.9558" width="0.1524" layer="21"/>
<wire x1="4.699" y1="-1.9558" x2="5.08" y2="-1.5748" width="0.1524" layer="21" curve="90"/>
<wire x1="-5.08" y1="1.5748" x2="-4.699" y2="1.9558" width="0.1524" layer="21" curve="-90"/>
<wire x1="4.699" y1="1.9558" x2="5.08" y2="1.5748" width="0.1524" layer="21" curve="-90"/>
<wire x1="-5.08" y1="-1.5748" x2="-4.699" y2="-1.9558" width="0.1524" layer="21" curve="90"/>
<wire x1="-4.699" y1="-1.9558" x2="4.699" y2="-1.9558" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.5748" x2="5.08" y2="1.5748" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.5748" x2="-5.08" y2="-1.5748" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.508" x2="-5.08" y2="-0.508" width="0.1524" layer="21" curve="-180"/>
<wire x1="-5.08" y1="-1.6002" x2="5.08" y2="-1.6002" width="0.0508" layer="21"/>
<smd name="1" x="-4.445" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="16" x="-4.445" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="2" x="-3.175" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="3" x="-1.905" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="15" x="-3.175" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="14" x="-1.905" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="4" x="-0.635" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="13" x="-0.635" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="5" x="0.635" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="12" x="0.635" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="6" x="1.905" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="7" x="3.175" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="11" x="1.905" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="10" x="3.175" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="8" x="4.445" y="-3.0734" dx="0.6604" dy="2.032" layer="1"/>
<smd name="9" x="4.445" y="3.0734" dx="0.6604" dy="2.032" layer="1"/>
<text x="-4.064" y="-0.635" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="-5.461" y="-1.778" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<rectangle x1="-0.889" y1="1.9558" x2="-0.381" y2="3.0988" layer="51"/>
<rectangle x1="-4.699" y1="-3.0988" x2="-4.191" y2="-1.9558" layer="51"/>
<rectangle x1="-3.429" y1="-3.0988" x2="-2.921" y2="-1.9558" layer="51"/>
<rectangle x1="-2.159" y1="-3.0734" x2="-1.651" y2="-1.9304" layer="51"/>
<rectangle x1="-0.889" y1="-3.0988" x2="-0.381" y2="-1.9558" layer="51"/>
<rectangle x1="-2.159" y1="1.9558" x2="-1.651" y2="3.0988" layer="51"/>
<rectangle x1="-3.429" y1="1.9558" x2="-2.921" y2="3.0988" layer="51"/>
<rectangle x1="-4.699" y1="1.9558" x2="-4.191" y2="3.0988" layer="51"/>
<rectangle x1="0.381" y1="-3.0988" x2="0.889" y2="-1.9558" layer="51"/>
<rectangle x1="1.651" y1="-3.0988" x2="2.159" y2="-1.9558" layer="51"/>
<rectangle x1="2.921" y1="-3.0988" x2="3.429" y2="-1.9558" layer="51"/>
<rectangle x1="4.191" y1="-3.0988" x2="4.699" y2="-1.9558" layer="51"/>
<rectangle x1="0.381" y1="1.9558" x2="0.889" y2="3.0988" layer="51"/>
<rectangle x1="1.651" y1="1.9558" x2="2.159" y2="3.0988" layer="51"/>
<rectangle x1="2.921" y1="1.9558" x2="3.429" y2="3.0988" layer="51"/>
<rectangle x1="4.191" y1="1.9558" x2="4.699" y2="3.0988" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="2001A">
<wire x1="-7.62" y1="10.16" x2="7.62" y2="10.16" width="0.4064" layer="94"/>
<wire x1="7.62" y1="-12.7" x2="7.62" y2="10.16" width="0.4064" layer="94"/>
<wire x1="7.62" y1="-12.7" x2="-7.62" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="-7.62" y1="10.16" x2="-7.62" y2="-12.7" width="0.4064" layer="94"/>
<text x="-7.62" y="10.922" size="1.778" layer="95">&gt;NAME</text>
<text x="-7.62" y="-15.24" size="1.778" layer="96">&gt;VALUE</text>
<pin name="I1" x="-12.7" y="7.62" length="middle" direction="in"/>
<pin name="I2" x="-12.7" y="5.08" length="middle" direction="in"/>
<pin name="I3" x="-12.7" y="2.54" length="middle" direction="in"/>
<pin name="I4" x="-12.7" y="0" length="middle" direction="in"/>
<pin name="I5" x="-12.7" y="-2.54" length="middle" direction="in"/>
<pin name="I6" x="-12.7" y="-5.08" length="middle" direction="in"/>
<pin name="I7" x="-12.7" y="-7.62" length="middle" direction="in"/>
<pin name="O1" x="12.7" y="7.62" length="middle" direction="oc" rot="R180"/>
<pin name="O2" x="12.7" y="5.08" length="middle" direction="oc" rot="R180"/>
<pin name="O3" x="12.7" y="2.54" length="middle" direction="oc" rot="R180"/>
<pin name="O4" x="12.7" y="0" length="middle" direction="oc" rot="R180"/>
<pin name="O5" x="12.7" y="-2.54" length="middle" direction="oc" rot="R180"/>
<pin name="O6" x="12.7" y="-5.08" length="middle" direction="oc" rot="R180"/>
<pin name="O7" x="12.7" y="-7.62" length="middle" direction="oc" rot="R180"/>
<pin name="CD+" x="12.7" y="-10.16" length="middle" direction="pas" rot="R180"/>
<pin name="GND" x="-12.7" y="-10.16" length="middle" direction="pwr"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ULN2003A" prefix="IC">
<description>&lt;b&gt;DRIVER ARRAY&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="2001A" x="0" y="0"/>
</gates>
<devices>
<device name="N" package="DIL16">
<connects>
<connect gate="A" pin="CD+" pad="9"/>
<connect gate="A" pin="GND" pad="8"/>
<connect gate="A" pin="I1" pad="1"/>
<connect gate="A" pin="I2" pad="2"/>
<connect gate="A" pin="I3" pad="3"/>
<connect gate="A" pin="I4" pad="4"/>
<connect gate="A" pin="I5" pad="5"/>
<connect gate="A" pin="I6" pad="6"/>
<connect gate="A" pin="I7" pad="7"/>
<connect gate="A" pin="O1" pad="16"/>
<connect gate="A" pin="O2" pad="15"/>
<connect gate="A" pin="O3" pad="14"/>
<connect gate="A" pin="O4" pad="13"/>
<connect gate="A" pin="O5" pad="12"/>
<connect gate="A" pin="O6" pad="11"/>
<connect gate="A" pin="O7" pad="10"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="D" package="SO16">
<connects>
<connect gate="A" pin="CD+" pad="9"/>
<connect gate="A" pin="GND" pad="8"/>
<connect gate="A" pin="I1" pad="1"/>
<connect gate="A" pin="I2" pad="2"/>
<connect gate="A" pin="I3" pad="3"/>
<connect gate="A" pin="I4" pad="4"/>
<connect gate="A" pin="I5" pad="5"/>
<connect gate="A" pin="I6" pad="6"/>
<connect gate="A" pin="I7" pad="7"/>
<connect gate="A" pin="O1" pad="16"/>
<connect gate="A" pin="O2" pad="15"/>
<connect gate="A" pin="O3" pad="14"/>
<connect gate="A" pin="O4" pad="13"/>
<connect gate="A" pin="O5" pad="12"/>
<connect gate="A" pin="O6" pad="11"/>
<connect gate="A" pin="O7" pad="10"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="+3V3">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="+3V3" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="+5V">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="+5V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+3V3" prefix="+3V3">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="+3V3" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+5V" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="+5V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="stm32f0discovery" deviceset="STM32F0DISCOVERY-DEVICE" device=""/>
<part name="IC1" library="uln-udn" deviceset="ULN2003A" device="N"/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="GND3" library="supply1" deviceset="GND" device=""/>
<part name="GND4" library="supply1" deviceset="GND" device=""/>
<part name="GND5" library="supply1" deviceset="GND" device=""/>
<part name="+3V1" library="supply1" deviceset="+3V3" device=""/>
<part name="P+1" library="supply1" deviceset="+5V" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="0" y="0"/>
<instance part="IC1" gate="A" x="78.74" y="22.86"/>
<instance part="GND1" gate="1" x="-30.48" y="-45.72"/>
<instance part="GND2" gate="1" x="30.48" y="-45.72"/>
<instance part="GND3" gate="1" x="30.48" y="33.02"/>
<instance part="GND4" gate="1" x="-30.48" y="33.02"/>
<instance part="GND5" gate="1" x="-30.48" y="15.24"/>
<instance part="+3V1" gate="G$1" x="-30.48" y="40.64"/>
<instance part="P+1" gate="1" x="30.48" y="40.64"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND3"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="-30.48" y1="-43.18" x2="-22.86" y2="-43.18" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND5"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="30.48" y1="-43.18" x2="22.86" y2="-43.18" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<pinref part="GND4" gate="1" pin="GND"/>
<wire x1="-22.86" y1="35.56" x2="-30.48" y2="35.56" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND5" gate="1" pin="GND"/>
<pinref part="U$1" gate="G$1" pin="GND1"/>
<wire x1="-30.48" y1="17.78" x2="-22.86" y2="17.78" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND3" gate="1" pin="GND"/>
<pinref part="U$1" gate="G$1" pin="GND4"/>
<wire x1="30.48" y1="35.56" x2="22.86" y2="35.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="+3V3" class="0">
<segment>
<pinref part="+3V1" gate="G$1" pin="+3V3"/>
<pinref part="U$1" gate="G$1" pin="3V"/>
<wire x1="-30.48" y1="38.1" x2="-22.86" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="+5V" class="0">
<segment>
<pinref part="P+1" gate="1" pin="+5V"/>
<pinref part="U$1" gate="G$1" pin="5V"/>
<wire x1="30.48" y1="38.1" x2="22.86" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
