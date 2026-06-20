__int64 __fastcall inst_info_release(__int64 a1, __int64 a2)
{
  __int64 v3; // x19

  if ( (msm_vidc_debug & 4) != 0 )
  {
    v3 = a2;
    printk(&unk_80467, "low ", 0xFFFFFFFFLL, "codec", *(_QWORD *)(a1 + 696));
    a2 = v3;
  }
  *(_QWORD *)(a2 + 32) = 0;
  return 0;
}
