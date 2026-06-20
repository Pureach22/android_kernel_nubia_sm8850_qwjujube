__int64 __fastcall sde_hw_intf_v1_get_status(__int64 a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  int v5; // w8
  int v6; // w21
  __int64 v7; // x1
  __int64 v8; // x9

  *a2 = sde_reg_read(a1, 620) & 1;
  result = sde_reg_read(a1, 4);
  v5 = *a2;
  a2[1] = (int)result < 0;
  if ( v5 )
  {
    v6 = sde_reg_read(a1, 692);
    if ( (((unsigned int)sde_reg_read(a1, 4) | v6) & 0x80000000) != 0
      && (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 33LL) & 8) != 0 )
    {
      v7 = 164;
    }
    else
    {
      v7 = 172;
    }
    *((_DWORD *)a2 + 1) = sde_reg_read(a1, v7);
    result = sde_reg_read(a1, 176);
    v8 = 8;
    v5 = (unsigned __int16)result;
  }
  else
  {
    v8 = 4;
    *((_DWORD *)a2 + 2) = 0;
  }
  *(_DWORD *)&a2[v8] = v5;
  return result;
}
