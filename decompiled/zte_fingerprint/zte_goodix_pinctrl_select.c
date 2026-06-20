__int64 __fastcall zte_goodix_pinctrl_select(__int64 a1, char a2)
{
  __int64 v3; // x21
  unsigned __int64 v4; // x8
  __int64 result; // x0
  const char *v6; // x1
  unsigned int v7; // w19

  if ( (a2 & 1) != 0 )
    v3 = 128;
  else
    v3 = 136;
  printk(&unk_86FE);
  v4 = *(_QWORD *)(a1 + v3);
  LODWORD(result) = -22;
  v6 = "not a valid '%s' pinstate\n";
  if ( v4 && v4 <= 0xFFFFFFFFFFFFF000LL )
  {
    result = pinctrl_select_state(*(_QWORD *)(a1 + 120), *(_QWORD *)(a1 + v3));
    if ( !(_DWORD)result )
      return result;
    v6 = "can not set %s pins\n";
  }
  v7 = result;
  dev_err(*(_QWORD *)(a1 + 24) + 16LL, v6);
  return v7;
}
