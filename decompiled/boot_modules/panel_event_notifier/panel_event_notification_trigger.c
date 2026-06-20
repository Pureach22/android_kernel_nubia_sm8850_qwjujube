__int64 __fastcall panel_event_notification_trigger(unsigned int a1, __int64 a2)
{
  __int64 v4; // x21
  _DWORD *v5; // x22
  __int64 v6; // x21
  _DWORD *v7; // x22
  __int64 v8; // x21
  _DWORD *v9; // x22
  __int64 result; // x0
  __int64 v11; // x21
  _DWORD *v12; // x22

  if ( a1 - 1 > 1 )
    return printk(&unk_6567);
  mutex_lock(&panel_event_notifier_entries_lock);
  if ( *(_QWORD *)(a2 + 16) != qword_6598 )
    goto LABEL_3;
  if ( dword_65A0 != a1 )
  {
    printk(&unk_6514);
LABEL_3:
    mutex_unlock(&panel_event_notifier_entries_lock);
    goto LABEL_9;
  }
  v5 = (_DWORD *)panel_event_notifier_entries;
  v4 = qword_6590;
  mutex_unlock(&panel_event_notifier_entries_lock);
  if ( v5 )
  {
    if ( *(v5 - 1) != 1074884503 )
      __break(0x8236u);
    ((void (__fastcall *)(_QWORD, __int64, __int64))v5)(a1, a2, v4);
  }
LABEL_9:
  mutex_lock(&panel_event_notifier_entries_lock);
  if ( *(_QWORD *)(a2 + 16) != qword_65B8 )
  {
LABEL_10:
    mutex_unlock(&panel_event_notifier_entries_lock);
    goto LABEL_16;
  }
  if ( dword_65C0 != a1 )
  {
    printk(&unk_6514);
    goto LABEL_10;
  }
  v7 = (_DWORD *)qword_65A8;
  v6 = qword_65B0;
  mutex_unlock(&panel_event_notifier_entries_lock);
  if ( v7 )
  {
    if ( *(v7 - 1) != 1074884503 )
      __break(0x8236u);
    ((void (__fastcall *)(_QWORD, __int64, __int64))v7)(a1, a2, v6);
  }
LABEL_16:
  mutex_lock(&panel_event_notifier_entries_lock);
  if ( *(_QWORD *)(a2 + 16) == qword_65D8 )
  {
    if ( dword_65E0 == a1 )
    {
      v9 = (_DWORD *)qword_65C8;
      v8 = qword_65D0;
      mutex_unlock(&panel_event_notifier_entries_lock);
      if ( v9 )
      {
        if ( *(v9 - 1) != 1074884503 )
          __break(0x8236u);
        ((void (__fastcall *)(_QWORD, __int64, __int64))v9)(a1, a2, v8);
      }
      goto LABEL_23;
    }
    printk(&unk_6514);
  }
  mutex_unlock(&panel_event_notifier_entries_lock);
LABEL_23:
  mutex_lock(&panel_event_notifier_entries_lock);
  if ( *(_QWORD *)(a2 + 16) != qword_65F8 )
    return mutex_unlock(&panel_event_notifier_entries_lock);
  if ( dword_6600 != a1 )
  {
    printk(&unk_6514);
    return mutex_unlock(&panel_event_notifier_entries_lock);
  }
  v12 = (_DWORD *)qword_65E8;
  v11 = qword_65F0;
  result = mutex_unlock(&panel_event_notifier_entries_lock);
  if ( v12 )
  {
    if ( *(v12 - 1) != 1074884503 )
      __break(0x8236u);
    return ((__int64 (__fastcall *)(_QWORD, __int64, __int64))v12)(a1, a2, v11);
  }
  return result;
}
