__int64 __fastcall _cam_isp_ctx_enqueue_request_in_order(__int64 a1, _QWORD *a2, char a3)
{
  _QWORD *v6; // x22
  _QWORD *v7; // x9
  _QWORD *v8; // x10
  unsigned __int64 v9; // x6
  unsigned __int64 v10; // x8
  _QWORD *v11; // x11
  _QWORD *v12; // x8
  __int64 v13; // x2
  _QWORD *v14; // x1
  _QWORD *v15; // x9
  _QWORD *v16; // x10
  _QWORD *v17; // x11
  _QWORD *v18; // x8
  _QWORD *v19; // x1
  __int64 result; // x0
  _QWORD v21[3]; // [xsp+8h] [xbp-18h] BYREF

  v21[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = v21;
  v21[1] = v21;
  if ( (a3 & 1) != 0 )
    raw_spin_lock_bh(a1 + 120);
  v6 = (_QWORD *)(a1 + 144);
  v7 = *(_QWORD **)(a1 + 152);
  if ( *(_QWORD *)(a1 + 144) == a1 + 144 )
  {
    if ( v6 == a2 || v7 == a2 || (_QWORD *)*v7 != v6 )
    {
      _list_add_valid_or_report(a2);
    }
    else
    {
      *(_QWORD *)(a1 + 152) = a2;
      *a2 = v6;
      a2[1] = v7;
      *v7 = a2;
    }
  }
  else
  {
    if ( v7 != v6 )
    {
      v8 = v21;
      while ( 1 )
      {
        v9 = a2[3];
        v10 = v7[3];
        if ( v9 >= v10 )
          break;
        v11 = (_QWORD *)v7[1];
        if ( (_QWORD *)*v11 == v7 && (v12 = (_QWORD *)*v7, *(_QWORD **)(*v7 + 8LL) == v7) )
        {
          v12[1] = v11;
          *v11 = v12;
        }
        else
        {
          _list_del_entry_valid_or_report(v7);
        }
        *v7 = v7;
        v7[1] = v7;
        v13 = v21[0];
        if ( *(_QWORD **)(v21[0] + 8LL) != v8 || v7 == v8 || v7 == (_QWORD *)v21[0] )
        {
          _list_add_valid_or_report(v7);
        }
        else
        {
          *(_QWORD *)(v21[0] + 8LL) = v7;
          *v7 = v13;
          v7[1] = v8;
          v21[0] = v7;
        }
        v7 = v11;
        if ( v11 == v6 )
          goto LABEL_24;
      }
      if ( v9 == v10 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "__cam_isp_ctx_enqueue_request_in_order",
          1101,
          "Received duplicated request %lld, ctx_idx: %u link: 0x%x",
          v9,
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
    }
LABEL_24:
    v14 = *(_QWORD **)(a1 + 152);
    if ( v6 == a2 || v14 == a2 || (_QWORD *)*v14 != v6 )
    {
      _list_add_valid_or_report(a2);
    }
    else
    {
      *(_QWORD *)(a1 + 152) = a2;
      *a2 = v6;
      a2[1] = v14;
      *v14 = a2;
    }
    v15 = (_QWORD *)v21[0];
    v16 = v21;
    if ( (_QWORD *)v21[0] != v21 )
    {
      do
      {
        v17 = (_QWORD *)*v15;
        v18 = (_QWORD *)v15[1];
        if ( (_QWORD *)*v18 == v15 && (_QWORD *)v17[1] == v15 )
        {
          v17[1] = v18;
          *v18 = v17;
        }
        else
        {
          _list_del_entry_valid_or_report(v15);
        }
        *v15 = v15;
        v15[1] = v15;
        v19 = *(_QWORD **)(a1 + 152);
        if ( v15 == v6 || v15 == v19 || (_QWORD *)*v19 != v6 )
        {
          _list_add_valid_or_report(v15);
        }
        else
        {
          *(_QWORD *)(a1 + 152) = v15;
          *v15 = v6;
          v15[1] = v19;
          *v19 = v15;
        }
        v15 = v17;
      }
      while ( v17 != v16 );
    }
  }
  result = _cam_isp_ctx_update_event_record(*(_QWORD *)(a1 + 256), 0, a2, 0);
  if ( (a3 & 1) != 0 )
    result = raw_spin_unlock_bh(a1 + 120);
  _ReadStatusReg(SP_EL0);
  return result;
}
