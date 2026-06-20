__int64 __fastcall msg_encode_end(__int64 result)
{
  if ( !result )
    return printk(&unk_823C, "msg_encode_end");
  *(_BYTE *)(result + 1) = *(_BYTE *)(result + 260) - 2;
  *(_WORD *)(result + 2) = *(_WORD *)result;
  return result;
}
