__int64 __fastcall drm_dp_aux_crc_work(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  _QWORD *v3; // x22
  unsigned int v4; // w0
  __int64 v5; // x5
  int v6; // w8
  int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w0
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 v14; // x1
  int v15; // w0
  _BYTE v16[4]; // [xsp+Ch] [xbp-24h] BYREF
  int v17; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int16 v18; // [xsp+14h] [xbp-1Ch]
  __int64 v19; // [xsp+18h] [xbp-18h] BYREF
  int v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result - 56);
  v18 = 0;
  v17 = 0;
  v20 = 0;
  v19 = 0;
  if ( v1 )
  {
    if ( *(_BYTE *)(v1 + 2064) == 1 )
    {
      v2 = result;
      v3 = (_QWORD *)(result - 1320);
      do
      {
        result = drm_crtc_wait_one_vblank(v1);
        if ( *(_BYTE *)(v1 + 2064) != 1 )
          break;
        v16[0] = 0;
        v4 = drm_dp_dpcd_read(v3, 0x270u, (__int64)v16, 1);
        v5 = v4;
        if ( (v4 & 0x80000000) == 0 )
        {
          if ( (v16[0] & 1) == 0 )
            __break(0x800u);
          v5 = drm_dp_dpcd_read(v3, 0x246u, (__int64)v16, 1);
          if ( (v5 & 0x80000000) == 0 )
          {
            v6 = v16[0] & 0xF;
            if ( v6 == *(unsigned __int8 *)(v2 + 32) )
              goto LABEL_14;
            *(_BYTE *)(v2 + 32) = v6;
            v7 = drm_dp_dpcd_read(v3, 0x240u, (__int64)&v17, 6);
            v5 = v7 & (unsigned int)(v7 >> 31);
          }
        }
        if ( (_DWORD)v5 != -11 )
          goto LABEL_20;
LABEL_14:
        usleep_range_state(1000, 2000, 2);
        v16[0] = 0;
        v8 = drm_dp_dpcd_read(v3, 0x270u, (__int64)v16, 1);
        v5 = v8;
        if ( (v8 & 0x80000000) != 0 )
          goto LABEL_20;
        if ( (v16[0] & 1) == 0 )
          __break(0x800u);
        v9 = drm_dp_dpcd_read(v3, 0x246u, (__int64)v16, 1);
        v5 = v9;
        if ( (v9 & 0x80000000) != 0 )
          goto LABEL_20;
        v10 = v16[0] & 0xF;
        if ( v10 == *(unsigned __int8 *)(v2 + 32) )
        {
          v5 = 4294967285LL;
LABEL_20:
          if ( (_DWORD)v5 )
            goto LABEL_21;
          goto LABEL_4;
        }
        *(_BYTE *)(v2 + 32) = v10;
        v15 = drm_dp_dpcd_read(v3, 0x240u, (__int64)&v17, 6);
        v5 = v15 & (unsigned int)(v15 >> 31);
        if ( (_DWORD)v5 )
        {
LABEL_21:
          if ( (_DWORD)v5 == -11 )
          {
            v11 = *(_QWORD *)(v2 - 64);
            if ( v11 )
              v12 = *(_QWORD *)(v11 + 8);
            else
              v12 = 0;
            result = _drm_dev_dbg(0, v12, 2, "%s: Get CRC failed after retrying: %d\n", *v3, 4294967285LL);
          }
          else
          {
            v13 = *(_QWORD *)(v2 - 64);
            if ( v13 )
              v14 = *(_QWORD *)(v13 + 8);
            else
              v14 = 0;
            result = _drm_dev_dbg(0, v14, 2, "%s: Failed to get a CRC: %d\n", *v3, v5);
          }
          continue;
        }
LABEL_4:
        LODWORD(v19) = (unsigned __int16)v17;
        HIDWORD(v19) = HIWORD(v17);
        v20 = v18;
        result = drm_crtc_add_crc_entry(v1, 0, 0, &v19);
      }
      while ( (*(_BYTE *)(v1 + 2064) & 1) != 0 );
    }
  }
  else
  {
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
