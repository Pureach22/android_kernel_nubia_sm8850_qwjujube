bool __fastcall _dsc_trans_trigger(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x20
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  if ( (unsigned int)qdf_list_remove_front((_DWORD *)(a1 + 8), v5) )
    v3 = 0;
  else
    v3 = v5[0] - 16LL;
  if ( v3 )
  {
    *(_QWORD *)a1 = *(_QWORD *)(v3 + 8);
    qdf_event_set(v3 + 32, v2);
  }
  _ReadStatusReg(SP_EL0);
  return v3 != 0;
}
