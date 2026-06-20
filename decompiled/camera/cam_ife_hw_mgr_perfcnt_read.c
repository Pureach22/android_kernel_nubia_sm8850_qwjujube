__int64 __fastcall cam_ife_hw_mgr_perfcnt_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v7; // w22
  size_t v8; // x4
  int v9; // w0
  size_t v10; // x0
  __int64 result; // x0
  char string[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v13; // [xsp+10h] [xbp-100h]
  __int64 v14; // [xsp+18h] [xbp-F8h]
  __int64 v15; // [xsp+20h] [xbp-F0h]
  __int64 v16; // [xsp+28h] [xbp-E8h]
  __int64 v17; // [xsp+30h] [xbp-E0h]
  __int64 v18; // [xsp+38h] [xbp-D8h]
  __int64 v19; // [xsp+40h] [xbp-D0h]
  __int64 v20; // [xsp+48h] [xbp-C8h]
  __int64 v21; // [xsp+50h] [xbp-C0h]
  __int64 v22; // [xsp+58h] [xbp-B8h]
  __int64 v23; // [xsp+60h] [xbp-B0h]
  __int64 v24; // [xsp+68h] [xbp-A8h]
  __int64 v25; // [xsp+70h] [xbp-A0h]
  __int64 v26; // [xsp+78h] [xbp-98h]
  __int64 v27; // [xsp+80h] [xbp-90h]
  __int64 v28; // [xsp+88h] [xbp-88h]
  __int64 v29; // [xsp+90h] [xbp-80h]
  __int64 v30; // [xsp+98h] [xbp-78h]
  __int64 v31; // [xsp+A0h] [xbp-70h]
  __int64 v32; // [xsp+A8h] [xbp-68h]
  __int64 v33; // [xsp+B0h] [xbp-60h]
  __int64 v34; // [xsp+B8h] [xbp-58h]
  __int64 v35; // [xsp+C0h] [xbp-50h]
  __int64 v36; // [xsp+C8h] [xbp-48h]
  __int64 v37; // [xsp+D0h] [xbp-40h]
  __int64 v38; // [xsp+D8h] [xbp-38h]
  __int64 v39; // [xsp+E0h] [xbp-30h]
  __int64 v40; // [xsp+E8h] [xbp-28h]
  __int64 v41; // [xsp+F0h] [xbp-20h]
  __int64 v42; // [xsp+F8h] [xbp-18h]
  __int64 v43; // [xsp+100h] [xbp-10h]
  __int64 v44; // [xsp+108h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  *(_QWORD *)string = 0;
  v13 = 0;
  v7 = scnprintf(string, 256, "\n***** ISP PERF COUNTERS *****\n\n");
  v8 = HIDWORD(qword_3A85AC);
  if ( qword_3A85AC )
  {
    if ( v7 > 0x100 )
      goto LABEL_11;
    v7 += scnprintf(
            &string[v7],
            256 - v7,
            "Available counters IFE: %u SFE: %u\n\n",
            qword_3A85AC,
            HIDWORD(qword_3A85AC));
    if ( v7 > 0x100 )
      goto LABEL_11;
    v9 = scnprintf(
           &string[v7],
           256 - v7,
           "To choose counter write to same file - \"<hw>_<counter_index>_<reg_val>\"\nEx. \"ife_1_6619140\"\n\n");
  }
  else
  {
    if ( v7 >= 0x101 )
    {
LABEL_11:
      __break(0x5512u);
      goto LABEL_12;
    }
    v9 = scnprintf(&string[v7], 256 - v7, "NOT SUPPORTED\n\n");
  }
  if ( v9 + v7 > 0x100 )
    goto LABEL_11;
  scnprintf(&string[v9 + v7], 256 - (v9 + v7), "*****************************\n");
  v10 = strnlen(string, 0x100u);
  v8 = v10;
  if ( v10 >= 0x101 )
  {
LABEL_12:
    _fortify_panic(2, 256, v8 + 1);
LABEL_13:
    _fortify_panic(4, 256, 257);
  }
  if ( v10 == 256 )
    goto LABEL_13;
  result = simple_read_from_buffer(a2, a3, a4, string, v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
