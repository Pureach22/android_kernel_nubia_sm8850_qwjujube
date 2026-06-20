__int64 __fastcall sde_plane_get_frame_data(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x23
  int *v6; // x21
  __int64 v7; // x22
  __int64 result; // x0
  void (*v9)(void); // x8
  __int64 (*v10)(void); // x8
  void (*v11)(void); // x8
  __int64 (*v12)(void); // x8
  __int64 (*v13)(void); // x8

  if ( !a1 )
    return printk(&unk_226FC0, "sde_plane_get_frame_data");
  if ( !*(_QWORD *)a1 )
    goto LABEL_6;
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v4 )
    goto LABEL_6;
  v5 = *(unsigned int *)(v4 + 5912);
  v6 = (int *)(a1 + 104);
  v7 = *(_QWORD *)(a1 + 1768);
  *a2 = *(_DWORD *)(a1 + 104);
  if ( (unsigned int)v5 >= 3 )
  {
    __break(0x5512u);
LABEL_6:
    v5 = 0;
    v6 = (int *)(a1 + 104);
    v7 = *(_QWORD *)(a1 + 1768);
    *a2 = *(_DWORD *)(a1 + 104);
  }
  result = *(_QWORD *)(a1 + 2208);
  if ( *(_QWORD *)(result + 8 * v5 + 1024) )
  {
    a2[1] = *(_DWORD *)(v7 + 2762);
    v9 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8 * v5 + 1024);
    if ( *((_DWORD *)v9 - 1) != -1909247538 )
      __break(0x8228u);
    v9();
    result = *(_QWORD *)(a1 + 2208);
  }
  v10 = *(__int64 (**)(void))(result + 8 * v5 + 1000);
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != -1189149286 )
      __break(0x8228u);
    a2[8] = v10();
    result = *(_QWORD *)(a1 + 2208);
  }
  v11 = *(void (**)(void))(result + 8 * v5 + 976);
  if ( v11 && a2[8] )
  {
    if ( *((_DWORD *)v11 - 1) != 42675746 )
      __break(0x8228u);
    v11();
    result = *(_QWORD *)(a1 + 2208);
  }
  v12 = *(__int64 (**)(void))(result + 8 * v5 + 952);
  if ( v12 )
  {
    if ( *((_DWORD *)v12 - 1) != -1189149286 )
      __break(0x8228u);
    a2[9] = v12();
    result = *(_QWORD *)(a1 + 2208);
  }
  v13 = *(__int64 (**)(void))(result + 8 * v5 + 928);
  if ( v13 && a2[9] )
  {
    if ( *((_DWORD *)v13 - 1) != 42675746 )
      __break(0x8228u);
    result = v13();
  }
  if ( *((_QWORD *)a2 + 4) )
  {
    result = sde_evtlog_log(sde_dbg_base_evtlog, "sde_plane_get_frame_data", 5616, -1, *v6, a2[8], a2[9], 60333, 239);
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "plane%d ubwc_error:0x%x meta_error:0x%x\n", *v6, a2[8], a2[9]);
  }
  return result;
}
