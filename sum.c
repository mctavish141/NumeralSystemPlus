int sum( int aLeft, int aRight )
{
   __asm
   {
      mov eax, aLeft    ; Получить первый аргумент
      mov ecx, aRight  ; Получить второй аргумент
      add eax, ecx     ; EAX = EAX + ECX
   }
   // Результат возвращается из EAX
}
