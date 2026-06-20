bool __fastcall _dsc_trans_abort(__int64 a1)
{
  __int64 v1; // x1
  _BYTE *v2; // x19
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  if ( (unsigned int)qdf_list_remove_front((_DWORD *)(a1 + 8), v4) )
    v2 = nullptr;
  else
    v2 = (_BYTE *)(v4[0] - 16LL);
  if ( v2 )
  {
    *v2 = 1;
    qdf_event_set((__int64)(v2 + 32), v1);
  }
  _ReadStatusReg(SP_EL0);
  return v2 != nullptr;
}
