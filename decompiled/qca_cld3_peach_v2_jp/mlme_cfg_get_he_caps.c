__int64 __fastcall mlme_cfg_get_he_caps(__int64 a1, __int64 a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8
  __int64 v6; // x10
  __int64 v7; // x12
  __int64 v8; // x13
  __int64 v9; // x11
  __int64 v10; // x9
  __int64 v11; // x10

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v4 = psoc_ext_obj_fl;
  v6 = *(_QWORD *)(v4 + 1372);
  v7 = *(_QWORD *)(v4 + 1348);
  v8 = *(_QWORD *)(v4 + 1356);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(v4 + 1364);
  *(_QWORD *)(a2 + 24) = v6;
  *(_QWORD *)a2 = v7;
  *(_QWORD *)(a2 + 8) = v8;
  v9 = *(_QWORD *)(v4 + 1380);
  v10 = *(_QWORD *)(v4 + 1388);
  v11 = *(_QWORD *)(v4 + 1396);
  LODWORD(v4) = *(_DWORD *)(v4 + 1404);
  *(_QWORD *)(a2 + 32) = v9;
  *(_DWORD *)(a2 + 56) = v4;
  *(_QWORD *)(a2 + 40) = v10;
  *(_QWORD *)(a2 + 48) = v11;
  return 0;
}
