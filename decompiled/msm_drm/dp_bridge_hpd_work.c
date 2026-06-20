__int64 __fastcall dp_bridge_hpd_work(__int64 a1)
{
  __int64 *v2; // x20
  __int64 v3; // x8
  void (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  int v6; // w8
  __int64 v7; // x10
  void (__fastcall *v8)(_QWORD); // x9
  void (__fastcall *v9)(_QWORD); // x10
  __int64 v10; // x0
  void *v11; // x0
  const char *v12; // x1

  v2 = (__int64 *)(a1 - 88);
  mutex_lock(a1 + 120);
  if ( *(_BYTE *)(a1 + 113) == 1 )
  {
    if ( v2 )
    {
      v3 = *(_QWORD *)(a1 + 104);
      *(_BYTE *)(a1 - 71) = 1;
      if ( v3 )
      {
        v4 = *(void (__fastcall **)(_QWORD))(v3 + 16);
        if ( v4 )
        {
          v5 = *v2;
          if ( *((_DWORD *)v4 - 1) != 711998475 )
            __break(0x8228u);
          v4(v5);
        }
      }
      return mutex_unlock(a1 + 120);
    }
    v11 = &unk_256395;
    v12 = "dp_bridge_hpd_attention";
LABEL_23:
    printk(v11, v12);
    return mutex_unlock(a1 + 120);
  }
  if ( !v2 )
  {
    v11 = &unk_256395;
    goto LABEL_22;
  }
  v6 = *(unsigned __int8 *)(a1 + 112);
  v7 = *(_QWORD *)(a1 + 104);
  *(_WORD *)(a1 - 72) = (unsigned __int8)v6;
  *(_BYTE *)(a1 - 70) = v6;
  if ( !v7
    || (v8 = *(void (__fastcall **)(_QWORD))v7) == nullptr
    || (v9 = *(void (__fastcall **)(_QWORD))(v7 + 8)) == nullptr )
  {
    v11 = &unk_2115E8;
LABEL_22:
    v12 = "dp_bridge_hpd_connect";
    goto LABEL_23;
  }
  v10 = *v2;
  if ( v6 )
  {
    if ( *((_DWORD *)v8 - 1) != 711998475 )
      __break(0x8229u);
    v8(v10);
  }
  else
  {
    if ( *((_DWORD *)v9 - 1) != 711998475 )
      __break(0x822Au);
    v9(v10);
  }
  return mutex_unlock(a1 + 120);
}
