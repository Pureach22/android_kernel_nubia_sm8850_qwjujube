__int64 __fastcall get_object_id(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  int v4; // w8
  unsigned int v6; // w19
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_11;
  if ( a1 == 1 )
  {
LABEL_3:
    result = 0;
    *a2 = 1;
    goto LABEL_12;
  }
  v4 = *(_DWORD *)(a1 + 12);
  result = 4294967287LL;
  if ( v4 > 7 )
  {
    if ( v4 == 8 )
      goto LABEL_3;
    if ( v4 != 16 )
      goto LABEL_12;
LABEL_11:
    result = 0;
    *a2 = 0;
    goto LABEL_12;
  }
  if ( v4 == 1 )
  {
    result = 0;
    *a2 = *(_QWORD *)(a1 + 16);
  }
  else if ( v4 == 2 )
  {
    v7 = 0;
    raw_spin_lock(&xa_si_objects);
    v6 = _xa_alloc_cyclic(&xa_si_objects, &v7, a1, 0x80000001FFFFFFFFLL, &alloc_si_object_id_xa_si_last_id, 3264);
    raw_spin_unlock(&xa_si_objects);
    if ( (v6 & 0x80000000) != 0 )
    {
      result = v6;
    }
    else
    {
      result = 0;
      *a2 = v7;
    }
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
