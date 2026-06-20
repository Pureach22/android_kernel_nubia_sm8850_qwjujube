__int64 __fastcall drm_dp_i2c_xfer(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x19
  size_t v4; // x23
  int v6; // w8
  __int64 v8; // x26
  unsigned __int16 *v9; // x25
  signed __int16 v10; // w8
  int v11; // w10
  char v12; // w9
  char v13; // w8
  int v14; // w0
  signed __int16 v15; // w8
  int v16; // w9
  char v17; // w10
  char v18; // w8
  char v19; // w9
  unsigned int v20; // w9
  unsigned int v21; // w27
  unsigned int v22; // w9
  __int64 v23; // x8
  __int64 v24; // x1
  size_t v25; // x5
  int v26; // w0
  unsigned int v27; // w24
  __int64 v28; // x8
  int v29; // w9
  char v30; // w9
  __int64 v32; // [xsp+8h] [xbp-38h] BYREF
  __int64 v33; // [xsp+10h] [xbp-30h]
  size_t v34; // [xsp+18h] [xbp-28h]
  __int64 v35; // [xsp+20h] [xbp-20h] BYREF
  __int64 v36; // [xsp+28h] [xbp-18h]
  size_t v37; // [xsp+30h] [xbp-10h]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 24);
  if ( (*(_BYTE *)(v3 + 1553) & 1) != 0 )
  {
    LODWORD(v4) = -16;
  }
  else
  {
    v6 = dp_aux_i2c_transfer_size;
    v32 = 0;
    v33 = 0;
    v34 = 0;
    if ( dp_aux_i2c_transfer_size <= 1 )
      v6 = 1;
    if ( v6 >= 16 )
      v6 = 16;
    dp_aux_i2c_transfer_size = v6;
    if ( a3 )
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = (unsigned __int16 *)(a2 + 16 * v8);
        v33 = 0;
        v34 = 0;
        v10 = v9[1];
        v11 = v10;
        v12 = v10 & 1 | 4;
        v13 = v10 & 1;
        LODWORD(v32) = *v9;
        if ( v11 >= 0 )
          v13 = v12;
        BYTE4(v32) = v13;
        v14 = drm_dp_i2c_do_msg(v3, &v32);
        v15 = v9[1];
        v16 = v15;
        v17 = v15 & 1 | 4;
        v18 = v15 & 1;
        if ( v16 >= 0 )
          v19 = v17;
        else
          v19 = v18;
        BYTE4(v32) = v19;
        if ( v14 < 0 )
        {
          LODWORD(v4) = v14;
          goto LABEL_41;
        }
        v20 = v9[2];
        if ( v9[2] )
          break;
LABEL_9:
        if ( ++v8 == a3 )
        {
          LODWORD(v4) = a3;
          goto LABEL_41;
        }
      }
      v21 = 0;
      LODWORD(v4) = dp_aux_i2c_transfer_size;
      while ( 1 )
      {
        v22 = v20 - v21;
        v23 = *((_QWORD *)v9 + 1) + v21;
        if ( (unsigned int)v4 >= v22 )
          v4 = v22;
        else
          v4 = (unsigned int)v4;
        v37 = v4;
        v33 = v23;
        v34 = v4;
        v35 = v32;
        v36 = v23;
        if ( (_DWORD)v4 )
        {
          while ( 1 )
          {
            v26 = drm_dp_i2c_do_msg(v3, &v35);
            v27 = v26;
            if ( v26 <= 0 )
              break;
            v25 = v37;
            if ( v37 > (unsigned int)v26 && v26 < (int)v4 )
            {
              v28 = *(_QWORD *)(v3 + 1256);
              if ( v28 )
                v24 = *(_QWORD *)(v28 + 8);
              else
                v24 = 0;
              _drm_dev_dbg(
                0,
                v24,
                2,
                "%s: Partial I2C reply: requested %zu bytes got %d bytes\n",
                *(const char **)v3,
                v37,
                v26);
              v25 = v37;
              LODWORD(v4) = v27;
            }
            v36 += v27;
            v37 = v25 - v27;
            if ( v25 == v27 )
              goto LABEL_34;
          }
          if ( v26 )
            LODWORD(v4) = v26;
          else
            LODWORD(v4) = -71;
        }
LABEL_34:
        v29 = (__int16)v9[1];
        v18 = v29 & 1;
        v30 = v29 >= 0 ? v29 & 1 | 4 : v29 & 1;
        BYTE4(v32) = v30;
        if ( (v4 & 0x80000000) != 0 )
          break;
        v20 = v9[2];
        v21 += v34;
        if ( v21 >= v20 )
          goto LABEL_9;
      }
    }
    else
    {
      v18 = 0;
      LODWORD(v4) = 0;
    }
LABEL_41:
    BYTE4(v32) = v18;
    v33 = 0;
    v34 = 0;
    drm_dp_i2c_do_msg(v3, &v32);
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v4;
}
