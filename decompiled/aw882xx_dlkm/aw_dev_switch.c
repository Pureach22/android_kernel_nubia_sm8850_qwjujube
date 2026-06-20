__int64 __fastcall aw_dev_switch(__int64 result, __int64 a2, char a3)
{
  __int64 v4; // x1
  __int64 v5; // x10
  void (__fastcall *v6)(__int64, __int64, __int64, __int64); // x11
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x21
  __int64 v10; // x0
  __int64 *v11; // x8
  __int64 v12; // x1

  v4 = *(unsigned int *)(a2 + 8);
  if ( (_DWORD)v4 != 255 )
  {
    v5 = 16;
    if ( (a3 & 1) == 0 )
      v5 = 20;
    v6 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(result + 1168);
    v7 = *(unsigned int *)(a2 + 12);
    v8 = *(unsigned int *)(a2 + v5);
    v9 = result;
    v10 = *(_QWORD *)(result + 120);
    if ( *((_DWORD *)v6 - 1) != 370515439 )
      __break(0x822Bu);
    v6(v10, v4, v7, v8);
    v11 = *(__int64 **)(v9 + 112);
    v12 = v11[14];
    if ( !v12 )
      v12 = *v11;
    return printk(&unk_25B06, v12, "aw_dev_switch");
  }
  return result;
}
