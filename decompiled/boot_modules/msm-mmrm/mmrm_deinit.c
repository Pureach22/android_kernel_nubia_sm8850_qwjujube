__int64 __fastcall mmrm_deinit(__int64 a1)
{
  __int64 v1; // x8
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w20

  if ( a1 && (v1 = *(_QWORD *)(a1 + 104)) != 0 && (v2 = *(__int64 (__fastcall **)(_QWORD))(v1 + 8)) != nullptr )
  {
    v4 = *(_QWORD *)(a1 + 96);
    if ( *((_DWORD *)v2 - 1) != -90674399 )
      __break(0x8228u);
    result = v2(v4);
    if ( (_DWORD)result )
    {
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
      {
        v6 = result;
        printk(&unk_C805, "err ", "mmrm_deinit");
        result = v6;
      }
      *(_QWORD *)(a1 + 96) = 0;
    }
  }
  else
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_CB00, "err ", "mmrm_deinit");
    return 4294967274LL;
  }
  return result;
}
