`timescale 1ns/1ps

module tb();

real CYCLE_100MHz = 10;
reg  clk_p;
wire clk_n;
reg  rst;

// clock gen
always begin
  clk_p = 0 ; #(CYCLE_100MHz/2);
  clk_p = 1 ; #(CYCLE_100MHz/2);
end
assign clk_n = ~clk_p;
// reset
initial begin
  rst = 1'b1;
  #100 rst = 1'b0;
  
  #10000000;
  $finish();
end

// inout  [63:0] ddr_c0_ddr4_dq(),
// inout  [7:0]  ddr_c0_ddr4_dqs_c(),
// inout  [7:0]  ddr_c0_ddr4_dqs_t(),
// inout  [7:0]  ddr_c0_ddr4_dm_dbi_n(),
// instance top
VCU118FPGATestHarness dut(
     .sys_clock_p(clk_p),
     .sys_clock_n(clk_n),

     .uart_txd(),
     .uart_rxd(),
     .uart_rtsn(),
     .uart_ctsn(),

     .sdio_spi_clk(),
     .sdio_spi_cs(),
     .sdio_spi_dat_0(),
     .sdio_spi_dat_1(),
     .sdio_spi_dat_2(),
     .sdio_spi_dat_3(),

     .ddr_c0_ddr4_dq(),
     .ddr_c0_ddr4_dqs_c(),
     .ddr_c0_ddr4_dqs_t(),
     .ddr_c0_ddr4_dm_dbi_n(),
     .reset(rst)
   );

endmodule	 
