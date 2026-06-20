__int64 __fastcall lpass_cdc_version_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9
  int v7; // w9
  const char *v8; // x9
  __int64 result; // x0
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // [xsp+0h] [xbp-30h] BYREF
  __int128 v13; // [xsp+8h] [xbp-28h] BYREF
  __int64 v14; // [xsp+18h] [xbp-18h]
  __int64 v15; // [xsp+20h] [xbp-10h]
  __int64 v16; // [xsp+28h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 64);
  v12 = a6;
  v13 = 0u;
  v14 = 0;
  v15 = 0;
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 + 848);
    if ( v7 > 4 )
    {
      switch ( v7 )
      {
        case 5:
          v8 = "LPASS-CDC_2_1\n";
          goto LABEL_19;
        case 6:
          v8 = "LPASS-CDC_2_5\n";
          goto LABEL_19;
        case 7:
          v8 = "LPASS-CDC_2_6\n";
          goto LABEL_19;
      }
    }
    else
    {
      switch ( v7 )
      {
        case 1:
          v8 = "LPASS-CDC_1_0\n";
          goto LABEL_19;
        case 2:
          v8 = "LPASS-CDC_1_1\n";
          goto LABEL_19;
        case 3:
          v8 = "LPASS-CDC_1_2\n";
LABEL_19:
          v10 = *(_QWORD *)v8;
          v11 = *(_QWORD *)(v8 + 7);
          *(_QWORD *)&v13 = v10;
          *(_QWORD *)((char *)&v13 + 7) = v11;
          result = simple_read_from_buffer(a4, a5, &v12, &v13, 14);
          goto LABEL_20;
      }
    }
    v8 = "VER_UNDEFINED\n";
    goto LABEL_19;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_version_read__rs, "lpass_cdc_version_read") )
    printk(&unk_D8A7, "lpass_cdc_version_read");
  result = -22;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
