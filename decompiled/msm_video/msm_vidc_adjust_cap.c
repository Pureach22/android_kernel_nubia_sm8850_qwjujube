__int64 __fastcall msm_vidc_adjust_cap(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  unsigned int *v4; // x8
  __int64 (*v5)(void); // x8
  __int64 result; // x0
  unsigned int v10; // w8
  unsigned int v11; // w20
  __int64 v12; // x0

  if ( a2 - 1 > 0xC3 )
    return 0;
  v4 = (unsigned int *)(a1 + 4320 + 168LL * a2);
  if ( *v4 - 197 < 0xFFFFFF3C || !*(_DWORD *)(a1 + 4320 + 168LL * *v4) )
    return 0;
  v5 = *((__int64 (**)(void))v4 + 19);
  if ( !v5 )
  {
    if ( a3 )
      ((void (*)(void))msm_vidc_update_cap_value)();
    return 0;
  }
  if ( *((_DWORD *)v5 - 1) != -611583898 )
    __break(0x8228u);
  result = v5();
  if ( (_DWORD)result && a1 && (msm_vidc_debug & 1) != 0 )
  {
    v10 = a2;
    v11 = result;
    v12 = cap_name(v10);
    printk(&unk_8EFCA, "err ", a1 + 340, a4, v12);
    return v11;
  }
  return result;
}
