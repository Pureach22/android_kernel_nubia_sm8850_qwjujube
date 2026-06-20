_WORD *__fastcall debug(_WORD *result, __int16 a2)
{
  if ( !result )
    return (_WORD *)printk(&unk_61D9B);
  *result = a2;
  return result;
}
