void qcom_check_tasks_done()
{
  int v0; // w9

  if ( dword_65C8 >= dword_65CC )
    v0 = dword_65D0 + 1;
  else
    v0 = 0;
  dword_65D0 = v0;
  if ( dword_65D4 && v0 >= dword_65D4 )
    panic("Detect IO wait too long time for multiple tasks!\n");
  dword_65C8 = 0;
}
