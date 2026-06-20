__int64 __fastcall dp_rx_page_pool_inactive_work(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x8
  _QWORD *v4; // x21
  __int64 v5; // x8
  __int64 v6; // x19
  _QWORD *v7; // x23
  __int64 v8; // x0
  _QWORD *v9; // x21
  void (*v10)(void); // x8
  _QWORD v11[4]; // [xsp+0h] [xbp-20h] BYREF

  v11[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(result + 440) == 1 )
  {
    v1 = *(_QWORD *)(result + 240);
    v2 = result;
    v11[0] = v11;
    v11[1] = v11;
    v11[2] = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 256);
    }
    else
    {
      raw_spin_lock_bh(result + 256);
      *(_QWORD *)(v2 + 264) |= 1uLL;
    }
    v4 = *(_QWORD **)(v2 + 416);
    if ( v4 != (_QWORD *)(v2 + 416) )
    {
      do
      {
        v7 = (_QWORD *)*v4;
        if ( v4[2] && (_qdf_page_pool_full_bh() & 1) != 0 )
        {
          qdf_list_remove_node(v2 + 416, v4);
          qdf_list_insert_back(v11, v4);
        }
        v4 = v7;
      }
      while ( v7 != (_QWORD *)(v2 + 416) );
    }
    v5 = *(_QWORD *)(v2 + 264);
    if ( (v5 & 1) != 0 )
    {
      *(_QWORD *)(v2 + 264) = v5 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v2 + 256);
    }
    else
    {
      result = raw_spin_unlock(v2 + 256);
    }
    if ( *(_BYTE *)(v2 + 440) == 1 )
    {
      result = qdf_list_empty((_QWORD *)(v2 + 416));
      if ( (result & 1) == 0 )
        result = _qdf_delayed_work_start(v2 + 296, 0x2710u);
    }
    v6 = v11[0];
    if ( (_QWORD *)v11[0] != v11 )
    {
      do
      {
        v8 = *(_QWORD *)(v6 + 16);
        v9 = *(_QWORD **)v6;
        if ( v8 && *(_BYTE *)(v6 + 40) && (v10 = *(void (**)(void))(*(_QWORD *)(v1 + 8) + 272LL)) != nullptr )
        {
          if ( *((_DWORD *)v10 - 1) != 820154707 )
            __break(0x8228u);
          v10();
          *(_BYTE *)(v6 + 40) = 0;
        }
        else
        {
          _qdf_page_pool_destroy(v8);
        }
        qdf_list_remove_node((__int64)v11, (_QWORD *)v6);
        result = _qdf_mem_free(v6);
        v6 = (__int64)v9;
      }
      while ( v9 != v11 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
