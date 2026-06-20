__int64 sub_82C4()
{
  __asm { SUBG            X21, X28, #0x2C0, #2 }
  return rmnet_shs_cpu_list_remove();
}
