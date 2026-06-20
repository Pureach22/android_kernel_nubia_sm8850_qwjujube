__int64 __fastcall sde_encoder_phys_vid_cont_splash_mode_set(__int64 result, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x11

  if ( !result || !a2 )
    return printk(&unk_211DA1, "sde_encoder_phys_vid_cont_splash_mode_set");
  v3 = a2[1];
  v2 = a2[2];
  *(_QWORD *)(result + 520) = *a2;
  *(_QWORD *)(result + 536) = v2;
  *(_QWORD *)(result + 528) = v3;
  v4 = a2[5];
  v5 = a2[3];
  v6 = a2[4];
  *(_QWORD *)(result + 568) = a2[6];
  *(_QWORD *)(result + 560) = v4;
  *(_QWORD *)(result + 552) = v6;
  *(_QWORD *)(result + 544) = v5;
  v7 = a2[9];
  v8 = a2[7];
  v9 = a2[8];
  *(_QWORD *)(result + 600) = a2[10];
  *(_QWORD *)(result + 592) = v7;
  *(_QWORD *)(result + 584) = v9;
  *(_QWORD *)(result + 576) = v8;
  v10 = a2[13];
  v11 = a2[11];
  v12 = a2[12];
  *(_QWORD *)(result + 632) = a2[14];
  LODWORD(v2) = *(_DWORD *)(result + 1020);
  *(_QWORD *)(result + 624) = v10;
  *(_QWORD *)(result + 616) = v12;
  *(_QWORD *)(result + 608) = v11;
  *(_DWORD *)(result + 832) = 4;
  if ( (v2 & 0x80000000) != 0 )
  {
    *(_DWORD *)(result + 1016) = *(_DWORD *)(result + 672);
    if ( (*(_DWORD *)(result + 1132) & 0x80000000) == 0 )
    {
LABEL_5:
      if ( (*(_DWORD *)(result + 1188) & 0x80000000) == 0 )
        goto LABEL_6;
      goto LABEL_12;
    }
  }
  else if ( (*(_DWORD *)(result + 1132) & 0x80000000) == 0 )
  {
    goto LABEL_5;
  }
  *(_DWORD *)(result + 1128) = *(_DWORD *)(result + 672);
  if ( (*(_DWORD *)(result + 1188) & 0x80000000) == 0 )
  {
LABEL_6:
    if ( (*(_DWORD *)(result + 2252) & 0x80000000) == 0 )
      goto LABEL_7;
    goto LABEL_13;
  }
LABEL_12:
  *(_DWORD *)(result + 1184) = *(_DWORD *)(result + 672);
  if ( (*(_DWORD *)(result + 2252) & 0x80000000) == 0 )
  {
LABEL_7:
    if ( (*(_DWORD *)(result + 1244) & 0x80000000) == 0 )
      goto LABEL_8;
    goto LABEL_14;
  }
LABEL_13:
  *(_DWORD *)(result + 2248) = *(_DWORD *)(result + 672);
  if ( (*(_DWORD *)(result + 1244) & 0x80000000) == 0 )
  {
LABEL_8:
    if ( (*(_DWORD *)(result + 1300) & 0x80000000) == 0 )
      return result;
LABEL_15:
    *(_DWORD *)(result + 1296) = *(_DWORD *)(result + 672);
    return result;
  }
LABEL_14:
  *(_DWORD *)(result + 1240) = *(_DWORD *)(result + 672);
  if ( (*(_DWORD *)(result + 1300) & 0x80000000) != 0 )
    goto LABEL_15;
  return result;
}
