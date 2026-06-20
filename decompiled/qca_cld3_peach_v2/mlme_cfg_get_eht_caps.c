__int64 __fastcall mlme_cfg_get_eht_caps(__int64 a1, __int64 a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8
  __int64 v6; // x10
  __int64 v7; // x12
  __int64 v8; // x13
  __int64 v9; // x10
  __int64 v10; // x12
  __int64 v11; // x13
  __int64 v12; // x11
  __int64 v13; // x9
  __int64 v14; // x10

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v4 = psoc_ext_obj_fl;
  v6 = *(_QWORD *)(v4 + 1524);
  v7 = *(_QWORD *)(v4 + 1500);
  v8 = *(_QWORD *)(v4 + 1508);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(v4 + 1516);
  *(_QWORD *)(a2 + 24) = v6;
  *(_QWORD *)a2 = v7;
  *(_QWORD *)(a2 + 8) = v8;
  v9 = *(_QWORD *)(v4 + 1556);
  v10 = *(_QWORD *)(v4 + 1532);
  v11 = *(_QWORD *)(v4 + 1540);
  *(_QWORD *)(a2 + 48) = *(_QWORD *)(v4 + 1548);
  *(_QWORD *)(a2 + 56) = v9;
  *(_QWORD *)(a2 + 32) = v10;
  *(_QWORD *)(a2 + 40) = v11;
  v12 = *(_QWORD *)(v4 + 1564);
  v13 = *(_QWORD *)(v4 + 1572);
  v14 = *(_QWORD *)(v4 + 1580);
  LODWORD(v4) = *(_DWORD *)(v4 + 1588);
  *(_QWORD *)(a2 + 64) = v12;
  *(_DWORD *)(a2 + 88) = v4;
  *(_QWORD *)(a2 + 72) = v13;
  *(_QWORD *)(a2 + 80) = v14;
  return 0;
}
