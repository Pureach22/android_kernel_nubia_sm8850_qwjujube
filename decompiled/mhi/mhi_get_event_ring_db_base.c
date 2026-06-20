__int64 __fastcall mhi_get_event_ring_db_base(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x0
  __int64 v4; // x20
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(a1 + 16);
  if ( (*(_WORD *)(v2 + 336) & 0xFDE) != 0
    && (v4 = *(_QWORD *)(*(_QWORD *)(v2 + 16) + 192LL), result = mhi_read_reg(v2), !(_DWORD)result) )
  {
    *a2 = *(_QWORD *)(v4 + 80);
  }
  else
  {
    result = 4294967291LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
