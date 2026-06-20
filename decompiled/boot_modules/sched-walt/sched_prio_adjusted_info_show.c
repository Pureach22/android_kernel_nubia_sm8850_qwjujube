__int64 __fastcall sched_prio_adjusted_info_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 result; // x0
  char s[8]; // [xsp+78h] [xbp-108h] BYREF
  __int64 v6; // [xsp+80h] [xbp-100h]
  __int64 v7; // [xsp+88h] [xbp-F8h]
  __int64 v8; // [xsp+90h] [xbp-F0h]
  __int64 v9; // [xsp+98h] [xbp-E8h]
  __int64 v10; // [xsp+A0h] [xbp-E0h]
  __int64 v11; // [xsp+A8h] [xbp-D8h]
  __int64 v12; // [xsp+B0h] [xbp-D0h]
  __int64 v13; // [xsp+B8h] [xbp-C8h]
  __int64 v14; // [xsp+C0h] [xbp-C0h]
  __int64 v15; // [xsp+C8h] [xbp-B8h]
  __int64 v16; // [xsp+D0h] [xbp-B0h]
  __int64 v17; // [xsp+D8h] [xbp-A8h]
  __int64 v18; // [xsp+E0h] [xbp-A0h]
  __int64 v19; // [xsp+E8h] [xbp-98h]
  __int64 v20; // [xsp+F0h] [xbp-90h]
  __int64 v21; // [xsp+F8h] [xbp-88h]
  __int64 v22; // [xsp+100h] [xbp-80h]
  __int64 v23; // [xsp+108h] [xbp-78h]
  __int64 v24; // [xsp+110h] [xbp-70h]
  __int64 v25; // [xsp+118h] [xbp-68h]
  __int64 v26; // [xsp+120h] [xbp-60h]
  __int64 v27; // [xsp+128h] [xbp-58h]
  __int64 v28; // [xsp+130h] [xbp-50h]
  __int64 v29; // [xsp+138h] [xbp-48h]
  __int64 v30; // [xsp+140h] [xbp-40h]
  __int64 v31; // [xsp+148h] [xbp-38h]
  __int64 v32; // [xsp+150h] [xbp-30h]
  __int64 v33; // [xsp+158h] [xbp-28h]
  __int64 v34; // [xsp+160h] [xbp-20h]
  __int64 v35; // [xsp+168h] [xbp-18h]
  __int64 v36; // [xsp+170h] [xbp-10h]
  __int64 v37; // [xsp+178h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v7 = 0;
  v8 = 0;
  *(_QWORD *)s = 0;
  v6 = 0;
  snprintf(
    s,
    0x100u,
    "[%d, %d, %d, %d, %d] [%d, %d, %d, %d, %d] [%d, %d, %d, %d, %d] [%d, %d, %d, %d, %d]\n",
    sched_prio_adjusted_info[0],
    dword_6A624,
    dword_6A628,
    dword_6A62C,
    dword_6A630,
    dword_6A634,
    dword_6A638,
    dword_6A63C,
    dword_6A640,
    dword_6A644,
    dword_6A648,
    dword_6A64C,
    dword_6A650,
    dword_6A654,
    dword_6A658,
    dword_6A65C,
    dword_6A660,
    dword_6A664,
    dword_6A668,
    dword_6A66C);
  LODWORD(result) = snprintf(a3, 0x100u, "%s\n", s);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
