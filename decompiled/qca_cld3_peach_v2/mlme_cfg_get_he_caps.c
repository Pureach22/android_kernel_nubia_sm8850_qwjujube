__int64 __fastcall mlme_cfg_get_he_caps(__int64 a1, __int64 a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8
  __int64 v6; // x9
  __int64 v7; // x11
  __int64 v8; // x12
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v4 = psoc_ext_obj_fl;
  v6 = *(_QWORD *)(v4 + 1392);
  v7 = *(_QWORD *)(v4 + 1368);
  v8 = *(_QWORD *)(v4 + 1376);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(v4 + 1384);
  *(_QWORD *)(a2 + 24) = v6;
  *(_QWORD *)a2 = v7;
  *(_QWORD *)(a2 + 8) = v8;
  LODWORD(v6) = *(_DWORD *)(v4 + 1424);
  v9 = *(_QWORD *)(v4 + 1416);
  v10 = *(_QWORD *)(v4 + 1400);
  v11 = *(_QWORD *)(v4 + 1408);
  *(_DWORD *)(a2 + 56) = v6;
  *(_QWORD *)(a2 + 40) = v11;
  *(_QWORD *)(a2 + 48) = v9;
  *(_QWORD *)(a2 + 32) = v10;
  return 0;
}
