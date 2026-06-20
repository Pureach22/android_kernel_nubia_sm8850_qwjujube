__int64 __fastcall lpg_lut_store_sdam(__int64 a1, __int64 a2, unsigned __int64 a3, unsigned int *a4, _DWORD *a5)
{
  unsigned __int64 v8; // x3
  unsigned int next_zero_area_off; // w24
  __int64 v12; // x8
  int v13; // w25
  __int64 v14; // x0
  unsigned __int16 v15; // w8
  __int64 result; // x0
  _BYTE v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned int *)(a1 + 84);
  v17[0] = 0;
  if ( v8 < a3 )
  {
    dev_err(*(_QWORD *)a1, "Pattern length (%zu) exceeds maximum pattern length (%d)\n", a3);
    result = 4294967274LL;
  }
  else
  {
    next_zero_area_off = bitmap_find_next_zero_area_off(*(_QWORD *)(a1 + 88), v8, 0, (unsigned int)a3, 0, 0);
    if ( *(_DWORD *)(a1 + 84) <= next_zero_area_off )
    {
      result = 4294967268LL;
    }
    else if ( a3 )
    {
      v12 = 0;
      v13 = 128;
      while ( 1 )
      {
        v14 = *(_QWORD *)(a1 + 112);
        v17[0] = *(_DWORD *)(a2 + 8 * v12 + 4);
        if ( v14 )
        {
          v15 = next_zero_area_off + v13 - 59;
        }
        else
        {
          v14 = *(_QWORD *)(a1 + 104);
          v15 = next_zero_area_off + v13;
        }
        result = nvmem_device_write(v14, v15, 1, v17);
        if ( (result & 0x80000000) != 0 )
          break;
        LODWORD(v12) = v13 - 127;
        ++v13;
        v12 = (int)v12;
        if ( (int)v12 >= a3 )
          goto LABEL_10;
      }
    }
    else
    {
LABEL_10:
      _bitmap_set(*(_QWORD *)(a1 + 88), next_zero_area_off, (unsigned int)a3);
      result = 0;
      *a4 = next_zero_area_off;
      *a5 = next_zero_area_off + a3 - 1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
