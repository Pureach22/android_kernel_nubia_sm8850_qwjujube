__int64 __fastcall qcom_glink_rx_defer(_QWORD *a1, __int64 a2)
{
  unsigned __int64 v3; // x21
  __int64 (*v4)(void); // x9
  unsigned __int64 v6; // x21
  _QWORD *v7; // x0
  _QWORD *v8; // x22
  void (*v9)(void); // x8
  _QWORD *v10; // x2
  _QWORD *v11; // x1
  void (*v12)(void); // x8

  v3 = (a2 + 7) & 0xFFFFFFFFFFFFFFF8LL;
  v4 = *(__int64 (**)(void))(a1[2] + 8LL);
  if ( *((_DWORD *)v4 - 1) != -1056647900 )
    __break(0x8229u);
  if ( v4() < v3 + 8 )
    return 4294967290LL;
  v6 = v3 + 24;
  v7 = (_QWORD *)_kmalloc_noprof(v6, 2336);
  v8 = v7;
  if ( !v7 )
    return 4294967284LL;
  *v7 = v7;
  v7[1] = v7;
  v9 = *(void (**)(void))(a1[2] + 16LL);
  if ( *((_DWORD *)v9 - 1) != -396915495 )
    __break(0x8228u);
  v9();
  raw_spin_lock(a1 + 16);
  v10 = a1 + 17;
  v11 = (_QWORD *)a1[18];
  if ( v8 == a1 + 17 || v11 == v8 || (_QWORD *)*v11 != v10 )
    goto LABEL_18;
  a1[18] = v8;
  if ( v6 < 8 || (*v8 = v10, (v6 & 0xFFFFFFFFFFFFFFF8LL) == 8) )
  {
    __break(1u);
LABEL_18:
    _list_add_valid_or_report(v8);
    goto LABEL_14;
  }
  v8[1] = v11;
  *v11 = v8;
LABEL_14:
  raw_spin_unlock(a1 + 16);
  queue_work_on(32, system_wq, a1 + 12);
  v12 = *(void (**)(void))(a1[2] + 24LL);
  if ( *((_DWORD *)v12 - 1) != -290755086 )
    __break(0x8228u);
  v12();
  return 0;
}
