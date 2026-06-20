__int64 __fastcall pmic_glink_rpmsg_callback(__int64 a1, const void *a2, __int64 a3)
{
  _QWORD *v3; // x23
  size_t v4; // x22
  unsigned __int64 v6; // x19
  __int64 v7; // x0
  _QWORD *v8; // x20
  size_t v9; // x1
  __int64 v10; // x0
  _QWORD *v11; // x2
  _QWORD *v12; // x1
  __int64 v13; // x9

  if ( (unsigned int)a3 <= 0xB )
  {
    printk(&unk_75BB, "pmic_glink_rpmsg_callback", a3);
    return 4294967274LL;
  }
  else
  {
    v3 = *(_QWORD **)(a1 + 152);
    v4 = (int)a3;
    v6 = (int)a3 + 24LL;
    v7 = _kmalloc_noprof(v6, 2336);
    v8 = (_QWORD *)v7;
    if ( v7 )
    {
      if ( v6 >= 0x10 && (v6 & 0xFFFFFFFFFFFFFFF8LL) != 0x10 )
      {
        *(_QWORD *)(v7 + 16) = v4;
        if ( v6 >= 0x18 )
          v9 = v6 - 24;
        else
          v9 = 0;
        if ( v9 < v4 )
          goto LABEL_18;
        memcpy((void *)(v7 + 24), a2, v4);
        v10 = raw_spin_lock_irqsave(v3 + 22);
        v11 = v3 + 32;
        v12 = (_QWORD *)v3[33];
        v13 = v10;
        if ( v8 == v3 + 32 || v8 == v12 || (_QWORD *)*v12 != v11 )
          goto LABEL_19;
        v3[33] = v8;
        *v8 = v11;
        if ( (v6 & 0xFFFFFFFFFFFFFFF8LL) != 8 )
        {
          v8[1] = v12;
          *v12 = v8;
LABEL_15:
          raw_spin_unlock_irqrestore(v3 + 22, v13);
          queue_work_on(32, v3[31], v3 + 23);
          return 0;
        }
      }
      __break(1u);
LABEL_18:
      _fortify_panic(17);
LABEL_19:
      _list_add_valid_or_report(v8, v12);
      goto LABEL_15;
    }
    return 4294967284LL;
  }
}
