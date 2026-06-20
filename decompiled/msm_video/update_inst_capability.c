__int64 __fastcall update_inst_capability(unsigned int *a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v3; // x8
  unsigned int v4; // w9

  if ( a1 && a2 )
  {
    if ( *a1 >= 0xC5 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_8A99C, "err ", 0xFFFFFFFFLL, "codec", "update_inst_capability");
        return 4294967274LL;
      }
      return 4294967274LL;
    }
    v3 = a2 + 8;
    *(_DWORD *)(a2 + 8 + 168LL * *a1) = *a1;
    if ( *a1 >= 0xC6
      || (*(_QWORD *)(v3 + 168LL * *a1 + 8) = *((_QWORD *)a1 + 2), *a1 > 0xC5)
      || (*(_QWORD *)(v3 + 168LL * *a1 + 16) = *((_QWORD *)a1 + 3), *a1 > 0xC5)
      || (*(_QWORD *)(v3 + 168LL * *a1 + 24) = *((_QWORD *)a1 + 4), *a1 > 0xC5)
      || (*(_QWORD *)(v3 + 168LL * *a1 + 32) = *((_QWORD *)a1 + 5), *a1 > 0xC5)
      || (*(_DWORD *)(v3 + 168LL * *a1 + 48) = a1[14], *a1 > 0xC5)
      || (*(_DWORD *)(v3 + 168LL * *a1 + 40) = a1[12], v4 = *a1, *a1 > 0xC5) )
    {
      __break(0x5512u);
      return msm_vidc_core_deinit_locked(a1, a2);
    }
    else
    {
      result = 0;
      *(_DWORD *)(v3 + 168LL * v4 + 44) = a1[13];
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    printk(&unk_834D4, "err ", 0xFFFFFFFFLL, "codec", "update_inst_capability");
    return 4294967274LL;
  }
  return result;
}
