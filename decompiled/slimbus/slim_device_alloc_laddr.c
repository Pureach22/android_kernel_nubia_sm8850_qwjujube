__int64 __fastcall slim_device_alloc_laddr(__int64 a1, char a2)
{
  __int64 v2; // x20
  _DWORD *v5; // x8
  unsigned int v6; // w0
  unsigned int v7; // w21
  _DWORD *v8; // x8
  __int64 v9; // x8
  void (__fastcall *v10)(__int64, __int64); // x8
  _BYTE v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 920);
  v12[0] = 0;
  if ( !v2 )
  {
    printk(&unk_885F, "slim_device_alloc_laddr");
    v7 = -22;
    goto LABEL_25;
  }
  mutex_lock(v2 + 80);
  v5 = *(_DWORD **)(v2 + 280);
  if ( !v5 )
  {
    if ( (a2 & 1) == 0 )
    {
LABEL_14:
      v7 = -22;
      goto LABEL_16;
    }
    v7 = ida_alloc_range(v2 + 56, 0, 254, 3264);
    if ( (v7 & 0x80000000) != 0 )
    {
LABEL_16:
      mutex_unlock(v2 + 80);
      goto LABEL_25;
    }
    v12[0] = v7;
    v8 = *(_DWORD **)(v2 + 272);
    if ( !v8 )
      goto LABEL_18;
LABEL_11:
    if ( *(v8 - 1) != -318340558 )
      __break(0x8228u);
    if ( !((unsigned int (__fastcall *)(__int64, __int64, _QWORD))v8)(v2, a1 + 912, v7) )
    {
      LOBYTE(v7) = v12[0];
      goto LABEL_18;
    }
    goto LABEL_14;
  }
  if ( *(v5 - 1) != -874373305 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *))v5)(v2, a1 + 912, v12);
  if ( (v6 & 0x80000000) != 0 )
  {
    v7 = v6;
    goto LABEL_16;
  }
  v7 = v12[0];
  v8 = *(_DWORD **)(v2 + 272);
  if ( v8 )
    goto LABEL_11;
LABEL_18:
  *(_BYTE *)(a1 + 932) = v7;
  *(_BYTE *)(a1 + 933) = 1;
  mutex_unlock(v2 + 80);
  if ( *(_DWORD *)(a1 + 928) != 1 )
  {
    v9 = *(_QWORD *)(a1 + 136);
    *(_DWORD *)(a1 + 928) = 1;
    if ( v9 )
    {
      v10 = *(void (__fastcall **)(__int64, __int64))(v9 - 8);
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != -1055034444 )
          __break(0x8228u);
        v10(a1, 1);
      }
    }
  }
  v7 = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v7;
}
