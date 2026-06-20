__int64 __fastcall dp_rx_srng_get_num_pending(__int64 a1, __int64 a2, unsigned int a3, char *a4)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v8; // w9
  unsigned int v9; // w8
  unsigned int v10; // w22
  __int64 v11; // x8
  unsigned int v12; // w23
  __int64 result; // x0
  bool v14; // cf
  char v15; // w8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 80);
  }
  else
  {
    raw_spin_lock_bh(a2 + 80);
    *(_QWORD *)(a2 + 88) |= 1uLL;
  }
  v8 = *(_DWORD *)(a2 + 120);
  v9 = **(_DWORD **)(a2 + 128);
  v10 = v9 - v8;
  *(_DWORD *)(a2 + 136) = v9;
  if ( v9 < v8 )
    v10 += *(_DWORD *)(a2 + 36);
  v11 = *(_QWORD *)(a2 + 88);
  v12 = *(_DWORD *)(a2 + 44);
  if ( (v11 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 88) = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 80);
  }
  else
  {
    raw_spin_unlock(a2 + 80);
  }
  result = v10 / v12;
  if ( a3 )
    v14 = (unsigned int)result >= a3 >> 1;
  else
    v14 = 0;
  v15 = v14;
  *a4 = v15;
  return result;
}
