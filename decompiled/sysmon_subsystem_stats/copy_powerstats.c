__int64 __fastcall copy_powerstats(_DWORD *a1, int a2)
{
  __int64 *v3; // x8
  _DWORD *v4; // x8
  unsigned int v5; // w2
  __int64 v6; // x7
  __int64 v7; // x25
  __int64 v8; // x23
  __int64 v9; // x26
  __int64 v10; // x17
  __int64 v11; // x1
  __int64 v12; // x4
  __int64 v13; // x6
  __int64 v14; // x19
  __int64 v15; // x30
  __int64 v16; // x21
  __int64 v17; // x24
  __int64 v18; // x27
  __int64 v19; // x15
  __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x10
  __int64 v23; // x28
  __int64 v24; // x12
  __int64 v25; // x22
  __int64 v26; // x13
  __int64 v27; // x20
  __int64 v28; // x14
  __int64 v29; // x5
  __int64 v30; // x16
  __int64 v31; // x9
  _DWORD *v32; // x8
  _DWORD *v33; // x12
  __int64 v35; // [xsp+8h] [xbp-F8h]
  __int64 v36; // [xsp+10h] [xbp-F0h]
  __int64 v37; // [xsp+18h] [xbp-E8h]
  __int64 v38; // [xsp+20h] [xbp-E0h]
  __int64 v39; // [xsp+28h] [xbp-D8h]
  __int64 v40; // [xsp+30h] [xbp-D0h]
  __int64 v41; // [xsp+38h] [xbp-C8h]
  __int64 v42; // [xsp+40h] [xbp-C0h]
  __int64 v43; // [xsp+48h] [xbp-B8h]
  __int64 v44; // [xsp+50h] [xbp-B0h]
  __int64 v45; // [xsp+58h] [xbp-A8h]
  __int64 v46; // [xsp+60h] [xbp-A0h]
  __int64 v47; // [xsp+68h] [xbp-98h]
  __int64 v48; // [xsp+70h] [xbp-90h]
  __int64 v49; // [xsp+78h] [xbp-88h]
  __int64 v50; // [xsp+80h] [xbp-80h]
  __int64 v51; // [xsp+88h] [xbp-78h]
  __int64 v52; // [xsp+90h] [xbp-70h]
  __int64 v53; // [xsp+98h] [xbp-68h]
  __int64 v54; // [xsp+A0h] [xbp-60h]
  __int64 v55; // [xsp+A8h] [xbp-58h]
  __int64 v56; // [xsp+B0h] [xbp-50h]
  __int64 v57; // [xsp+B8h] [xbp-48h]
  __int64 v58; // [xsp+C0h] [xbp-40h]
  __int64 v59; // [xsp+C8h] [xbp-38h]
  __int64 v60; // [xsp+D0h] [xbp-30h]
  __int64 v61; // [xsp+D8h] [xbp-28h]
  __int64 v62; // [xsp+E0h] [xbp-20h]
  __int64 v63; // [xsp+E8h] [xbp-18h]
  __int64 v64; // [xsp+F0h] [xbp-10h]

  switch ( a2 )
  {
    case 2:
      v3 = &qword_9608;
      break;
    case 5:
      v3 = &qword_9610;
      break;
    case 3:
      v3 = &qword_9618;
      break;
    default:
      printk(&unk_A0E2, "sysmon_subsystem_stats");
      return 1;
  }
  v4 = (_DWORD *)*v3;
  *a1 = *(unsigned __int8 *)v4;
  v5 = *(unsigned __int8 *)v4;
  a1[65] = v4[33];
  a1[66] = v4[34];
  if ( v5 >= 2 )
    a1[99] = v4[51];
  v64 = 48;
  a1[1] = v4[1];
  v41 = 46;
  v6 = 11;
  v59 = 30;
  v7 = 8;
  v63 = 32;
  v8 = 38;
  a1[33] = v4[17];
  v9 = 37;
  v54 = 28;
  v10 = 21;
  v53 = 12;
  v11 = 5;
  v39 = 43;
  v12 = 36;
  v52 = 27;
  v13 = 20;
  v51 = 42;
  v14 = 4;
  v50 = 26;
  v15 = 35;
  v62 = 16;
  v16 = 19;
  v49 = 10;
  v17 = 3;
  v43 = 47;
  v18 = 34;
  v38 = 41;
  v19 = 2;
  v61 = 31;
  v48 = 25;
  v60 = 15;
  v47 = 9;
  v58 = 14;
  v36 = 40;
  v57 = 45;
  v46 = 24;
  v56 = 29;
  v45 = 39;
  v37 = 22;
  v55 = 13;
  v44 = 23;
  v35 = 6;
  v20 = 18;
  v40 = 44;
  v42 = 7;
  if ( (a2 & 0xFFFFFFFE) == 2 )
  {
    v21 = 3;
    v22 = 4;
    v23 = 6;
    v24 = 7;
    v25 = 9;
    v26 = 10;
    v27 = 12;
    v28 = 13;
    v29 = 15;
    v30 = 16;
    if ( v5 >= 2 )
    {
      v64 = 82;
      a1[67] = v4[35];
      v29 = 81;
      v63 = 50;
      v36 = 43;
      v27 = 79;
      a1[2] = v4[2];
      v6 = 13;
      v25 = 77;
      v39 = 45;
      v41 = 47;
      v7 = 11;
      a1[34] = v4[18];
      v23 = 75;
      v10 = 25;
      v11 = 9;
      v12 = 74;
      v13 = 42;
      v14 = 24;
      v16 = 8;
      a1[68] = v4[36];
      v21 = 73;
      v17 = 41;
      v18 = 39;
      v19 = 7;
      v15 = 8;
      v9 = 41;
      v8 = 10;
      a1[3] = v4[3];
      v24 = 42;
      v38 = 12;
      v26 = 44;
      v40 = 14;
      v28 = 46;
      a1[35] = v4[19];
      v43 = 16;
      v30 = 48;
      a1[69] = v4[37];
      a1[4] = v4[4];
      a1[36] = v4[20];
      a1[70] = v4[38];
      a1[5] = v4[5];
      a1[37] = v4[21];
      v61 = 16;
      v62 = 32;
      v60 = 49;
      v59 = 31;
      v58 = 15;
      v57 = 80;
      a1[71] = v4[39];
      v55 = 30;
      v56 = 48;
      v54 = 14;
      v53 = 47;
      a1[6] = v4[6];
      v52 = 29;
      v50 = 46;
      v51 = 78;
      v49 = 28;
      v48 = 12;
      v47 = 45;
      a1[38] = v4[22];
      v45 = 76;
      v46 = 27;
      v44 = 44;
      v42 = 26;
      v37 = 10;
      v35 = 43;
      v22 = 40;
      a1[72] = v4[40];
      v20 = 23;
    }
  }
  else
  {
    v21 = 3;
    v22 = 4;
    v23 = 6;
    v24 = 7;
    v25 = 9;
    v26 = 10;
    v27 = 12;
    v28 = 13;
    v29 = 15;
    v30 = 16;
  }
  a1[v19] = v4[v19];
  a1[v18] = v4[v20];
  a1[v21] = v4[v17];
  a1[v15] = v4[v16];
  a1[v22] = v4[v14];
  a1[v12] = v4[v13];
  a1[v11] = v4[v11];
  a1[v9] = v4[v10];
  a1[v23] = v4[v35];
  a1[v8] = v4[v37];
  a1[v24] = v4[v42];
  a1[v45] = v4[v44];
  a1[v7] = v4[v7];
  a1[v36] = v4[v46];
  a1[v25] = v4[v47];
  a1[v38] = v4[v48];
  a1[v26] = v4[v49];
  a1[v51] = v4[v50];
  a1[v6] = v4[v6];
  a1[v39] = v4[v52];
  a1[v27] = v4[v53];
  a1[v40] = v4[v54];
  a1[v28] = v4[v55];
  a1[v57] = v4[v56];
  a1[v58] = v4[v58];
  a1[v41] = v4[v59];
  a1[v29] = v4[v60];
  a1[v43] = v4[v61];
  a1[v30] = v4[v62];
  a1[v64] = v4[v63];
  if ( v5 >= 4 )
  {
    v31 = 0;
    v32 = v4 + 90;
    do
    {
      v33 = &a1[v31 + 49];
      *(v33 - 32) = v32[v31];
      *v33 = v32[v31 + 16];
      if ( a2 == 2 )
        v33[34] = v32[v31 + 32];
      ++v31;
    }
    while ( v31 != 16 );
  }
  return 0;
}
