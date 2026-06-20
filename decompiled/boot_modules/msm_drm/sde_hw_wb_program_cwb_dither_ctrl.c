void __fastcall sde_hw_wb_program_cwb_dither_ctrl(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  unsigned int v6; // w19
  __int64 v8; // x23
  __int64 v9; // x8
  unsigned int v10; // w21
  unsigned int v11; // w22
  unsigned int v12; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v6 = a2;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = a5;
  v12 = 0;
  if ( !(unsigned int)sde_hw_wb_program_cwb_dither_validate(a1, a2, a3, a4, v13) )
  {
    v8 = a1 + 696;
    if ( (a1 == -696 || v6 != 1)
      && ((v8 = a1 + 1168, a1 == -1168) || v6 != 2)
      && ((v8 = a1 + 1640, a1 == -1640) || v6 != 3)
      && ((v8 = a1 + 2112, a1 == -2112) || v6 != 4) )
    {
      _drm_err("Not found pp id %d\n", 14);
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 40);
      v10 = *(_DWORD *)(v8 + 32);
      if ( (*(_QWORD *)(v9 + 32) & 0x400) != 0 )
      {
        v11 = *(_DWORD *)(*(_QWORD *)(v9 + 48) + 128LL);
        if ( (v13[0] & 1) != 0 )
        {
          ((void (__fastcall *)(__int64, __int64, unsigned int *))sde_hw_wb_program_cwb_dither_ctrl_common)(
            v8,
            a3,
            &v12);
          sde_reg_write(
            v8,
            v11 + 8,
            *(_DWORD *)(a3 + 28) & 0xF
          | ((*(_WORD *)(a3 + 36) & 0xF) << 8) & 0xFFF
          | (unsigned __int8)(16 * (*(_BYTE *)(a3 + 32) & 0xF))
          | ((*(_DWORD *)(a3 + 40) & 0xF) << 12),
            "base + offset");
          sde_reg_write(
            v8,
            v11 + 12,
            *(_DWORD *)(a3 + 44) & 0xF
          | ((*(_WORD *)(a3 + 52) & 0xF) << 8) & 0xFFF
          | (unsigned __int8)(16 * (*(_BYTE *)(a3 + 48) & 0xF))
          | ((*(_DWORD *)(a3 + 56) & 0xF) << 12),
            "base + offset");
          sde_reg_write(
            v8,
            v11 + 16,
            *(_DWORD *)(a3 + 60) & 0xF
          | ((*(_WORD *)(a3 + 68) & 0xF) << 8) & 0xFFF
          | (unsigned __int8)(16 * (*(_BYTE *)(a3 + 64) & 0xF))
          | ((*(_DWORD *)(a3 + 72) & 0xF) << 12),
            "base + offset");
          sde_reg_write(
            v8,
            v11 + 20,
            *(_DWORD *)(a3 + 76) & 0xF
          | ((*(_WORD *)(a3 + 84) & 0xF) << 8) & 0xFFF
          | (unsigned __int8)(16 * (*(_BYTE *)(a3 + 80) & 0xF))
          | ((*(_DWORD *)(a3 + 88) & 0xF) << 12),
            "base + offset");
          sde_reg_write(v8, v11, v12, "base");
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "cwb dither enabled, dcwb_idx %u pp_id %u\n", v6, v10);
        }
        else
        {
          sde_reg_write(v8, v11, 0, "base");
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "cwb dither disabled, dcwb_idx %u pp_id %u\n", v6, v10);
        }
      }
      else
      {
        _drm_err("Invalid ping-pong cwb config dcwb idx %d pp id %d\n", v6, v10);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
}
