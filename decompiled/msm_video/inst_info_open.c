__int64 __fastcall inst_info_open(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x20

  if ( (msm_vidc_debug & 4) != 0 )
  {
    v3 = a1;
    v4 = a2;
    printk(&unk_80437, "low ", 0xFFFFFFFFLL, "codec", *(_QWORD *)(a1 + 696));
    a1 = v3;
    a2 = v4;
  }
  *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 696);
  return 0;
}
