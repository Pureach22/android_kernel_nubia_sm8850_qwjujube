__int64 __fastcall queue_regulatory_request(__int64 a1)
{
  __int64 v1; // x9
  __int64 v3; // x10
  char v4; // w8
  _UNKNOWN **v5; // x0
  _QWORD *v6; // x1

  v1 = *(unsigned __int8 *)(a1 + 28);
  v3 = *(unsigned __int8 *)(a1 + 29);
  if ( (*((_BYTE *)&ctype + v1) & 2) != 0 )
    LOBYTE(v1) = v1 - 32;
  *(_BYTE *)(a1 + 28) = v1;
  if ( (*((_BYTE *)&ctype + v3) & 2) != 0 )
    v4 = v3 - 32;
  else
    v4 = v3;
  *(_BYTE *)(a1 + 29) = v4;
  raw_spin_lock(&reg_requests_lock);
  v5 = (_UNKNOWN **)(a1 + 48);
  v6 = off_4E40;
  if ( (_UNKNOWN **)(a1 + 48) == &reg_requests_list || off_4E40 == v5 || *off_4E40 != (_UNKNOWN *)&reg_requests_list )
  {
    _list_add_valid_or_report(v5, off_4E40);
  }
  else
  {
    off_4E40 = (_UNKNOWN **)(a1 + 48);
    *(_QWORD *)(a1 + 48) = &reg_requests_list;
    *(_QWORD *)(a1 + 56) = v6;
    *v6 = v5;
  }
  raw_spin_unlock(&reg_requests_lock);
  return queue_work_on(32, system_wq, &reg_work);
}
