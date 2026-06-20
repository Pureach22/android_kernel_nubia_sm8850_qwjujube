__int64 __fastcall mlme_cfg_get_orig_eht_caps(__int64 a1, __int64 a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8
  __int64 v6; // x9
  __int64 v7; // x11
  __int64 v8; // x12
  __int64 v9; // x9
  __int64 v10; // x11
  __int64 v11; // x12
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v4 = psoc_ext_obj_fl;
  v6 = *(_QWORD *)(v4 + 1616);
  v7 = *(_QWORD *)(v4 + 1592);
  v8 = *(_QWORD *)(v4 + 1600);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(v4 + 1608);
  *(_QWORD *)(a2 + 24) = v6;
  *(_QWORD *)a2 = v7;
  *(_QWORD *)(a2 + 8) = v8;
  v9 = *(_QWORD *)(v4 + 1648);
  v10 = *(_QWORD *)(v4 + 1624);
  v11 = *(_QWORD *)(v4 + 1632);
  *(_QWORD *)(a2 + 48) = *(_QWORD *)(v4 + 1640);
  *(_QWORD *)(a2 + 56) = v9;
  *(_QWORD *)(a2 + 32) = v10;
  *(_QWORD *)(a2 + 40) = v11;
  LODWORD(v9) = *(_DWORD *)(v4 + 1680);
  v12 = *(_QWORD *)(v4 + 1672);
  v13 = *(_QWORD *)(v4 + 1656);
  v14 = *(_QWORD *)(v4 + 1664);
  *(_DWORD *)(a2 + 88) = v9;
  *(_QWORD *)(a2 + 72) = v14;
  *(_QWORD *)(a2 + 80) = v12;
  *(_QWORD *)(a2 + 64) = v13;
  return 0;
}
