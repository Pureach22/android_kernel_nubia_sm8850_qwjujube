void __fastcall gsi_program_chan_ctx(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  unsigned int v3; // w4
  int v5; // w8
  unsigned int v6; // w19
  char *v7; // x9
  int v8; // w11
  int v9; // w10
  __int64 v10; // x2
  __int64 v11; // x2
  int v12; // w9
  int v13; // w10
  int v14; // w8
  unsigned int v15; // w8
  int v16; // w9
  __int64 v17; // [xsp+0h] [xbp-50h] BYREF
  int v18; // [xsp+8h] [xbp-48h] BYREF
  __int64 v19; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v20; // [xsp+14h] [xbp-3Ch]
  int v21; // [xsp+1Ch] [xbp-34h]
  int v22; // [xsp+20h] [xbp-30h]
  unsigned int v23; // [xsp+24h] [xbp-2Ch]
  __int64 v24; // [xsp+28h] [xbp-28h] BYREF
  __int64 v25; // [xsp+30h] [xbp-20h]
  int v26; // [xsp+38h] [xbp-18h]
  int v27; // [xsp+3Ch] [xbp-14h]
  int v28; // [xsp+40h] [xbp-10h]
  int v29; // [xsp+44h] [xbp-Ch]
  __int64 v30; // [xsp+48h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)a1;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  v17 = 0;
  if ( v3 < 0x10 && ((0xBBFFu >> v3) & 1) != 0 )
  {
    v22 = *(_DWORD *)(a1 + 4);
    v23 = v3;
    v5 = dword_2E370[v3];
    v6 = a2;
    v7 = (char *)&v19 + 4;
    v8 = a3;
    if ( *(_DWORD *)(gsi_ctx + 16) > 9u )
      v7 = (char *)&v17 + 4;
    v9 = *(_DWORD *)(a1 + 24);
    v10 = *(unsigned __int8 *)(a1 + 8);
    *(_DWORD *)v7 = v8;
    LODWORD(v20) = v5;
    v18 = v9;
    gsihal_write_reg_nk_fields(8, a2, v10, &v18);
    v11 = *(unsigned __int8 *)(a1 + 8);
    LODWORD(v17) = *(_DWORD *)(a1 + 28);
    gsihal_write_reg_nk_fields(52, v6, v11, &v17);
    gsihal_write_reg_nk(53, v6, *(unsigned __int8 *)(a1 + 8));
    gsihal_write_reg_nk(54, v6, *(unsigned __int8 *)(a1 + 8));
    v13 = *(_DWORD *)(a1 + 64);
    v12 = *(_DWORD *)(a1 + 68);
    v14 = *(unsigned __int8 *)(a1 + 72);
    v24 = 0;
    v25 = 0;
    v28 = v12;
    v29 = v14;
    v26 = 0;
    v27 = v13;
    v15 = *(_DWORD *)(gsi_ctx + 16);
    if ( v15 >= 4 )
    {
      v16 = *(_DWORD *)(a1 + 76);
      if ( v15 > 5 )
      {
        LODWORD(v25) = *(unsigned __int8 *)(a1 + 80);
        HIDWORD(v25) = v16;
        if ( v15 >= 8 )
        {
          HIDWORD(v24) = *(unsigned __int8 *)(a1 + 48);
          if ( v15 >= 0xA )
            LODWORD(v24) = *(unsigned __int8 *)(a1 + 49);
        }
      }
      else
      {
        v26 = *(_DWORD *)(a1 + 76);
      }
    }
    gsihal_write_reg_nk_fields(51, v6, *(unsigned __int8 *)(a1 + 8), &v24);
  }
  else
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Unsupported protocol %d\n", "gsi_program_chan_ctx", 2790, v3);
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
}
