__int64 set_kaanapali_hal_functions()
{
  hal_ops = (__int64)interrupt_init_iris2_kaanapali;
  qword_6C4B0 = (__int64)setup_dsp_uc_memmap_vpu5_kaanapali;
  qword_6C4B8 = (__int64)_power_off_controller_kaanapali;
  qword_6C4C0 = (__int64)_power_off_core_kaanapali;
  qword_6C4C8 = (__int64)_power_on_controller_kaanapali;
  qword_6C4D0 = (__int64)_power_on_core_kaanapali;
  qword_6C4D8 = (__int64)_noc_error_info_iris2_kaanapali;
  qword_6C4E0 = (__int64)_check_ctl_power_on_kaanapali;
  qword_6C4E8 = (__int64)_check_core_power_on_kaanapali;
  qword_6C4F0 = (__int64)_print_sidebandmanager_regs_kaanapali;
  qword_6C4F8 = (__int64)_set_registers_kaanapali;
  qword_6C500 = (__int64)_dump_noc_regs_kaanapali;
  qword_6C508 = (__int64)_enable_hw_power_collapse_kaanapali;
  qword_6C510 = (__int64)_check_tensilica_in_reset_kaanapali;
  return 0;
}
