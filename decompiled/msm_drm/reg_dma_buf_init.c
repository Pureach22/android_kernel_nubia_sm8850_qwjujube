__int64 __fastcall reg_dma_buf_init(unsigned __int64 *a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 ops; // x8
  __int64 result; // x0
  _DWORD *v8; // x8
  unsigned __int64 v9; // x0

  ops = sde_reg_dma_get_ops(a3);
  result = 4294966772LL;
  if ( ops && ops <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( a1 )
    {
      if ( *a1 )
      {
        return 0;
      }
      else
      {
        v8 = *(_DWORD **)(ops + 48);
        if ( *(v8 - 1) != 70798817 )
          __break(0x8228u);
        v9 = ((__int64 (__fastcall *)(_QWORD, _QWORD))v8)(a2, a3);
        *a1 = v9;
        if ( v9 > 0xFFFFFFFFFFFFF000LL || v9 == 0 )
          return 4294967274LL;
        else
          return 0;
      }
    }
    else
    {
      _drm_err("invalid buf\n");
      return 4294967274LL;
    }
  }
  return result;
}
