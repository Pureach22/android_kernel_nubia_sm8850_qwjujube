__int64 __fastcall config_show(__int64 a1, __int64 a2, const char *a3)
{
  __int64 v5; // x27
  __int64 v6; // x8
  _QWORD **v7; // x8
  _QWORD *v8; // x28
  int v9; // w26
  int v10; // w8
  __int64 v11; // x3
  int v12; // w0
  int v13; // w19
  size_t v14; // x26
  size_t v15; // x0
  size_t v16; // x2
  __int64 v17; // x22
  __int64 v19; // [xsp+0h] [xbp-50h]
  char string[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v21; // [xsp+10h] [xbp-40h]
  __int64 v22; // [xsp+18h] [xbp-38h]
  __int64 v23; // [xsp+20h] [xbp-30h]
  __int64 v24; // [xsp+28h] [xbp-28h]
  __int64 v25; // [xsp+30h] [xbp-20h]
  __int64 v26; // [xsp+38h] [xbp-18h]
  __int64 v27; // [xsp+40h] [xbp-10h]
  __int64 v28; // [xsp+48h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  *(_QWORD *)string = 0;
  v21 = 0;
  *a3 = 0;
  mutex_lock(v5 + 24);
  v6 = *(unsigned __int8 *)(v5 + 332);
  if ( *(_DWORD *)(v5 + 328) <= (unsigned int)v6 )
  {
    v9 = -22;
    dev_err(a1, "Select link list to program using curr_list\n");
LABEL_27:
    v13 = v9;
    goto LABEL_28;
  }
  v7 = (_QWORD **)(*(_QWORD *)(v5 + 312) + 16 * v6);
  v8 = *v7;
  if ( *v7 != v7 )
  {
    v9 = 0;
    v19 = a1;
    while ( 1 )
    {
      v10 = *((_DWORD *)v8 - 2);
      v11 = *((unsigned int *)v8 - 7);
      if ( v10 == 1 )
      {
        v12 = scnprintf(string, 64, "Index: 0x%x, Loop: %d\n", v11, *((_DWORD *)v8 - 6));
      }
      else if ( v10 == 3 )
      {
        v12 = scnprintf(
                string,
                64,
                "Write Index: 0x%x, Base: 0x%x, Offset: 0x%x, len: 0x%x APB: %d\n",
                v11,
                *((unsigned int *)v8 - 10),
                *((unsigned int *)v8 - 9),
                *((unsigned int *)v8 - 8),
                *((unsigned __int8 *)v8 - 12));
      }
      else
      {
        v12 = v10 == 2
            ? scnprintf(
                string,
                64,
                "Index: 0x%x, mask: 0x%x, val: 0x%x\n",
                v11,
                *((_DWORD *)v8 - 4),
                *((_DWORD *)v8 - 5))
            : scnprintf(
                string,
                64,
                "Read Index: 0x%x, Base: 0x%x, Offset: 0x%x, len: 0x%x APB: %d\n",
                v11,
                *((unsigned int *)v8 - 10),
                *((unsigned int *)v8 - 9),
                *((unsigned int *)v8 - 8),
                *((unsigned __int8 *)v8 - 12));
      }
      v13 = v12 + v9;
      if ( (unsigned int)(v12 + v9) > 0x1000 )
        break;
      v14 = strnlen(a3, 0x1000u);
      if ( v14 == -1 )
        goto LABEL_31;
      v15 = strnlen(string, 0x40u);
      if ( v15 >= 0x41 )
        goto LABEL_30;
      if ( v15 == 64 )
      {
        v15 = _fortify_panic(4, 64, 65);
LABEL_30:
        _fortify_panic(2, 64, v15 + 1);
LABEL_31:
        _fortify_panic(2, -1, v14 + 1);
      }
      if ( v14 <= 0xFFF )
      {
        if ( v15 + v14 >= 0x1000 )
          v16 = 4095 - v14;
        else
          v16 = v15;
        if ( v15 + v14 >= 0x1000 )
          v17 = 4095;
        else
          v17 = v15 + v14;
        memcpy((void *)&a3[v14], string, v16);
        a3[v17] = 0;
      }
      v9 = v13;
      v8 = (_QWORD *)*v8;
      if ( v8 == (_QWORD *)(*(_QWORD *)(v5 + 312) + 16LL * *(unsigned __int8 *)(v5 + 332)) )
        goto LABEL_28;
    }
    dev_err(v19, "DCC: Couldn't write complete config\n");
    goto LABEL_27;
  }
  v13 = 0;
LABEL_28:
  mutex_unlock(v5 + 24);
  _ReadStatusReg(SP_EL0);
  return v13;
}
