unsigned __int64 __fastcall reg_dmav1_setup_scaler3_adaptive_de(char *a1, __int64 a2, int a3, int *a4, unsigned int a5)
{
  unsigned __int64 result; // x0
  int v10; // w8
  int v11; // w9
  int v12; // w11
  int v13; // w13
  int v14; // w10
  int v15; // w8
  __int64 (__fastcall *v16)(_QWORD); // x9
  int v17; // w8
  _DWORD v18[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = sde_reg_dma_get_ops(a5);
  if ( result && result <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( a1 && a4 )
    {
      if ( *(_DWORD *)(a2 + 536) )
      {
        v10 = *(_DWORD *)(a2 + 556);
        v11 = *(unsigned __int16 *)(a2 + 552);
        v12 = *(_DWORD *)(a2 + 548);
        v13 = *(unsigned __int8 *)(a2 + 544);
        v14 = (unsigned __int8)*(_DWORD *)(a2 + 560) << 8;
        *(_DWORD *)a1 = 2;
        v15 = v11 | (v10 << 16);
        *((_DWORD *)a1 + 5) = a3 + 224;
        v18[2] = v14;
        *(_QWORD *)(a1 + 12) = 0;
        *((_QWORD *)a1 + 4) = v18;
        *((_QWORD *)a1 + 5) = 0xC00000000LL;
        v16 = *(__int64 (__fastcall **)(_QWORD))(result + 8);
        v18[0] = v15;
        v18[1] = v13 | (v12 << 16);
        if ( *((_DWORD *)v16 - 1) != -1839634494 )
          __break(0x8229u);
        result = v16(a1);
        if ( (_DWORD)result )
        {
          result = _drm_err("ade write failed ret %d\n", result);
        }
        else
        {
          v17 = *a4;
          *a4 |= 0x200u;
          if ( *(_DWORD *)(a2 + 540) && (v17 & 0x1000) == 0 && !*(_DWORD *)(a2 + 308) )
            *a4 = v17 | 0xA00;
        }
      }
    }
    else
    {
      result = _drm_err("invalid dma_write_cfg %pK scaler3_cfg %pK op_mode %pK\n", a1, (const void *)a2, a4);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
