__int64 __fastcall pattern_trig_attrs_mode(__int64 a1, __int64 a2)
{
  if ( (char **)a2 == &dev_attr_repeat || (char **)a2 == &dev_attr_pattern )
    return *(unsigned __int16 *)(a2 + 8);
  if ( (char **)a2 == &dev_attr_hr_pattern )
    return (unsigned __int16)word_E8;
  if ( (char **)a2 != &dev_attr_hw_pattern )
    return 0;
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 152) + 64LL) )
    return (unsigned __int16)word_108;
  return 0;
}
