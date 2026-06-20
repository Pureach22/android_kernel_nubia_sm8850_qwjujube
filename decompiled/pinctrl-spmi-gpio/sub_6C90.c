__int64 sub_6C90()
{
  __int64 v0; // x24
  __int16 v1; // h13

  *(_WORD *)(v0 + 1810) = v1;
  return pmic_gpio_child_offset_to_irq();
}
