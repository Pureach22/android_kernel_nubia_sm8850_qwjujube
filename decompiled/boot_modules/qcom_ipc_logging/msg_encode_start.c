__int64 __fastcall msg_encode_start(__int64 result, char a2)
{
  if ( !result )
    return printk(&unk_823C, "msg_encode_start");
  *(_BYTE *)result = a2;
  *(_BYTE *)(result + 1) = 0;
  *(_DWORD *)(result + 260) = 2;
  return result;
}
