__int64 __fastcall cam_cpas_hw_enable_tpg_mux_sel(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  _DWORD *v5; // x8
  unsigned int v6; // w20

  v2 = *(_QWORD *)(a1 + 3680);
  mutex_lock(a1);
  v5 = *(_DWORD **)(v2 + 8072);
  if ( v5 )
  {
    if ( *(v5 - 1) != -1929499818 )
      __break(0x8228u);
    v6 = ((__int64 (__fastcall *)(__int64, _QWORD))v5)(a1, a2);
    if ( v6 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_hw_enable_tpg_mux_sel",
        4167,
        "failed in tpg mux selection rc=%d",
        v6);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_enable_tpg_mux_sel",
      4171,
      "CPAS tpg mux sel not enabled");
    v6 = -22;
  }
  mutex_unlock(a1);
  return v6;
}
