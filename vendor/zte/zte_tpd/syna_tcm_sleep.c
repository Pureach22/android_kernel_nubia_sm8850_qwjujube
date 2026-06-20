__int64 __fastcall syna_tcm_sleep(__int64 a1, char a2, __int64 a3)
{
  __int64 (*v3)(void); // x9
  unsigned __int8 v4; // w20
  unsigned int v5; // w0
  unsigned int v6; // w8
  unsigned int v8; // w19
  __int64 v9; // x20
  char v10; // w21

  if ( a1 )
  {
    if ( !(_DWORD)a3 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
    {
      v9 = a1;
      v10 = a2;
      printk(unk_3BA3F, "syna_tcm_sleep", a3);
      a2 = v10;
      a1 = v9;
    }
    v3 = *(__int64 (**)(void))(a1 + 920);
    if ( (a2 & 1) != 0 )
      v4 = 44;
    else
      v4 = 45;
    /* CFI check removed */
    v5 = v3();
    v6 = 0;
    if ( (v5 & 0x80000000) != 0 )
    {
      v8 = v5;
      printk(unk_3C171, "syna_tcm_sleep", v4);
      return v8;
    }
  }
  else
  {
    printk(unk_3365A, "syna_tcm_sleep", a3);
    return (unsigned int)-241;
  }
  return v6;
}
