__int64 __fastcall aw882xx_monitor_start(__int64 a1)
{
  __int64 **v1; // x20
  __int64 *v3; // x8
  __int64 v4; // x1
  __int64 result; // x0
  int v6; // w1
  int v7; // w8
  __int64 (__fastcall *v8)(_QWORD); // x9
  __int64 v9; // x0
  int v10; // w10
  __int64 v11; // x1

  v1 = (__int64 **)(a1 - 560);
  _ReadStatusReg(SP_EL0);
  v3 = *(__int64 **)(a1 - 560);
  v4 = v3[14];
  if ( !v4 )
    v4 = *v3;
  result = printk(&unk_26EB3, v4, "aw882xx_monitor_start");
  v6 = *(_DWORD *)(a1 + 304);
  *(_WORD *)(a1 + 201) = 0;
  *(_DWORD *)(a1 + 236) = 0;
  *(_DWORD *)(a1 + 216) = 0;
  if ( v6 == 255 )
  {
    if ( *(_DWORD *)(a1 - 656) != 1 )
    {
LABEL_5:
      v7 = *(unsigned __int8 *)(a1 + 204);
      *(_BYTE *)(a1 + 200) = 1;
      if ( !v7 )
        result = queue_delayed_work_on(32, *(_QWORD *)(a1 - 488), a1, 0);
      goto LABEL_7;
    }
  }
  else
  {
    v8 = *(__int64 (__fastcall **)(_QWORD))(a1 + 488);
    v9 = *(_QWORD *)(a1 - 552);
    if ( *((_DWORD *)v8 - 1) != 1983062130 )
      __break(0x8229u);
    result = v8(v9);
    v10 = *(_DWORD *)(a1 + 312);
    *(_DWORD *)(a1 - 656) = v10 == 0;
    if ( v10 )
      goto LABEL_5;
  }
  v11 = (*v1)[14];
  if ( !v11 )
    v11 = **v1;
  result = printk(&unk_271C8, v11, "aw882xx_monitor_start");
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
