bool __fastcall msm_usbc_swap_gnd_mic(__int64 a1, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x0

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 784LL);
  printk(&unk_140EB, "msm_usbc_swap_gnd_mic", a2 & 1);
  if ( !*(_QWORD *)(v2 + 72) )
    return 0;
  if ( (byte_3205 & 1) != 0 )
  {
    v3 = 7;
  }
  else
  {
    if ( !dword_3200 )
      return 1;
    v3 = 4;
  }
  return (unsigned int)wcd_usbss_switch_update(v3, 1) == 0;
}
