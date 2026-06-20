__int64 __fastcall setSize(__int64 result, int a2)
{
  if ( !result )
    return printk(&unk_61D9B);
  *(_DWORD *)(result + 24) = a2;
  return result;
}
