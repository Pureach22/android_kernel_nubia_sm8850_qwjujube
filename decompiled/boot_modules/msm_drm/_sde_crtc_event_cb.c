_QWORD *__fastcall sde_crtc_event_cb(_QWORD *result)
{
  __int64 v1; // x19
  _QWORD *v2; // x20
  void (__fastcall *v3)(__int64, __int64); // x8
  _QWORD *v4; // x21
  __int64 v5; // x1
  __int64 v6; // x0
  __int64 v7; // x0
  _QWORD *v8; // x1
  __int64 v9; // x9
  __int64 v10; // x2

  if ( !result )
    return (_QWORD *)printk(&unk_23F082, "_sde_crtc_event_cb");
  v1 = result[5];
  v2 = result;
  if ( v1 )
  {
    v3 = (void (__fastcall *)(__int64, __int64))result[6];
    v4 = result - 2;
    if ( v3 )
    {
      v5 = result[7];
      v6 = result[5];
      if ( *((_DWORD *)v3 - 1) != -253167563 )
        __break(0x8228u);
      v3(v6, v5);
    }
    v7 = raw_spin_lock_irqsave(v1 + 7352);
    v8 = *(_QWORD **)(v1 + 7344);
    v9 = v7;
    v10 = v1 + 7336;
    if ( v4 == (_QWORD *)(v1 + 7336) || v8 == v4 || *v8 != v10 )
    {
      _list_add_valid_or_report(v2 - 2, v8);
    }
    else
    {
      *(_QWORD *)(v1 + 7344) = v4;
      *(v2 - 2) = v10;
      *(v2 - 1) = v8;
      *v8 = v4;
    }
    return (_QWORD *)raw_spin_unlock_irqrestore(v1 + 7352, v9);
  }
  return result;
}
